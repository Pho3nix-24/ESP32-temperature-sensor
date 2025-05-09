# ESP32 Temperature Control System
---

## 📝 Descripción

Este proyecto simula un sistema de control de temperatura básico. El **ESP32** lee la temperatura ambiental de un sensor y controla un **LED** que simula el comportamiento de un calentador. Cuando la temperatura baja de **27°C**, el LED se enciende para simular el calentador activado. Cuando la temperatura supera los **35°C**, el LED se apaga para simular la desactivación del calentador.

El objetivo es mantener la temperatura dentro del rango de **27°C a 35°C**, encendiendo el LED cuando la temperatura esté por debajo de 27°C, y apagándolo cuando la temperatura supere los 35°C. Un **encendedor** se utiliza como fuente de calor para alterar la temperatura cerca del sensor.


### Características:

- **Sensor de temperatura**: DHT11, DHT22 o LM35.
- **ESP32**: Microcontrolador que conecta el sensor y controla el LED.
- **LED como calentador**: El LED se enciende para simular un calentador.
- **Visualización en LCD**: Se muestra la temperatura en una pantalla LCD.
- **Control del encendedor**: Se puede usar un encendedor para aumentar la temperatura cerca del sensor.

---

## 💡 Requisitos

Antes de comenzar, asegúrate de tener lo siguiente:

- **ESP32**: Placa de desarrollo compatible.
- **Sensor de temperatura**: DHT11, DHT22 o LM35.
- **LED**: Para simular el calentador.
- **Pantalla LCD**: Para mostrar la temperatura y el estado del LED.
- **Cables de conexión**.
- **Software**:
  - Arduino IDE configurado con la placa ESP32
  - Librerías `DHT` para el DHT11/DHT22) y `LiquidCrystal` para controlar la pantalla LCD.

---

## 🛠️ Instalación

### 1. Configuración del Entorno de Desarrollo

- Abre el **Arduino IDE**.
- Ve a **Archivo** > **Preferencias** y en el campo **Gestor de URLs adicionales de tarjetas** agrega el siguiente enlace: https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_dev_index.json
  

- Ve a **Herramientas** > **Placa** y selecciona tu modelo de **ESP32**.
- Asegúrate de tener instaladas las librerías adecuadas:
- **DHT sensor library**: para leer datos del sensor DHT11 o DHT22.
- **Adafruit GFX** y **Adafruit LCD**: Para controlar la pantalla LCD.

### 2. Conexión del Hardware

- Conecta el sensor de temperatura al **ESP32** según el siguiente esquema (dependiendo del sensor que uses):

**Para un DHT11/DHT22:**
- **VCC** al **5V** (o **3.3V** dependiendo del sensor).
- **GND** a **GND**.
- **Data** al **GPIO que elijas (por ejemplo, GPIO 15)**.

**Para un LM35:**
- **VCC** al **5V**.
- **GND** a **GND**.
- **Salida de datos (Vout)** al **GPIO** de tu elección (por ejemplo, GPIO 34).

- Conecta el **LED** a un pin digital del ESP32, por ejemplo, **GPIO 2**.
- Conecta la **pantalla LCD** a los pines correspondientes (SDA y SCL) en el ESP32.





