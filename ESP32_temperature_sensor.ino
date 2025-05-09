#include <Wire.h>  // No es necesario si no usas I2C, pero no afecta
#include <LiquidCrystal.h>
#include <DHT.h>

// Configuración del LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(23, 22, 21, 19, 18, 5);

// Definición del sensor
#define DHTTYPE DHT11
#define DHTPIN 4
DHT dht(DHTPIN, DHTTYPE);

int LED1 = 14;  // Pin del LED

void setup() {
  lcd.begin(16, 2);               // Inicializa pantalla LCD 16x2
  lcd.clear();                    // Borra pantalla al inicio

  Serial.begin(115200);           // Inicializa comunicación serial
  dht.begin();                    // Inicializa sensor

  pinMode(LED1, OUTPUT);          // Configura pin LED como salida
}

void loop() {
  float h = dht.readHumidity();    // Lee humedad
  float t = dht.readTemperature(); // Lee temperatura

  if (isnan(h) || isnan(t)) {
    Serial.println("Error al leer el sensor DHT!");
    lcd.setCursor(0, 0);
    lcd.print("Error sensor DHT ");
    lcd.setCursor(0, 1);
    lcd.print("                ");  // limpia línea 2
    delay(2000);
    return;
  }

  // Control del LED
  if (t < 27.0) {
    digitalWrite(LED1, HIGH);
  } else if (t >= 35.0) {
    digitalWrite(LED1, LOW);
  }

  // Mostrar datos en LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t, 1);  // muestra temperatura con 1 decimal
  lcd.print(" C   "); // agrega espacios para limpiar sobrantes

  lcd.setCursor(0, 1);
  if (digitalRead(LED1) == HIGH) {
    lcd.print("Calentador: ON ");
  } else {
    lcd.print("Calentador:OFF ");
  }

  delay(1000);
}