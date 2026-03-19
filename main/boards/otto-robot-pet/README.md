# Otto Robot Pet - Gato/Perro con servo en la cola

Variante del Otto Robot para robots en forma de gato o perro con servo en la cola. Sin cámara, solo lo esencial para el robot Otto.

## Hardware

- **MCU**: ESP32-S3
- **Pantalla**: ST7789 (240x240) - SPI
- **Audio**: MAX98357A (I2S) + INMP441 (micrófono I2S)
- **Servos**: 5x MG90S
- **Alimentación**: Batería 3.7V Li-ion → TC4056 → MT3608 (5V) → ESP32

## Conexiones

### 1. Pantalla ST7789

| Pantalla | ESP32-S3 | Color |
|----------|----------|-------|
| GND | GND | Negro |
| VCC | 3.3V | Azul |
| SCL | GPIO 9 | Cian |
| SDA | GPIO 10 | Verde |
| RES | GPIO 11 | Azul oscuro |
| DC | GPIO 46 | Púrpura |
| CS | GND (pantalla) | Amarillo |
| BLK | GPIO 3 | Naranja |

### 2. Audio - MAX98357A (altavoz)

| MAX98357A | Conexión | **IMPORTANTE** |
|-----------|----------|----------------|
| LRC | GPIO 16 | |
| BCLK | GPIO 15 | |
| DIN | GPIO 7 | |
| **SD** | **GPIO 21** | Control de mute: LOW=mute, HIGH=unmute. El firmware activa el altavoz solo al reproducir |
| GND, GAIN | GND | |
| Vin | 3.7V o 5V | Alimentación |

### 3. Audio - INMP441 (micrófono)

| INMP441 | ESP32-S3 |
|---------|----------|
| SCK | GPIO 5 |
| WS | GPIO 4 |
| SD | GPIO 6 |
| L/R | GND |
| VDD | 3.3V |

### 4. Servomotores MG90S

| Servo | GPIO |
|-------|------|
| Antes (Front) | GPIO 17 |
| Izquierda (Left) | GPIO 18 |
| Derecha (Right) | GPIO 39 |
| Atrás (Back) | GPIO 38 |
| Cola (Tail) | GPIO 8 |

Todos comparten 5V y GND.

## Compilación

```bash
python scripts/release.py otto-robot-pet
```

O manualmente:
1. `idf.py set-target esp32s3`
2. `idf.py menuconfig` → Xiaozhi Assistant → Board Type → **Otto Robot Pet (Gato/Perro con cola)**
3. `idf.py build flash monitor`

## Configuración WiFi

El ESP32-S3 usa **provisioning por hotspot**: al encender crea la red `XiaoZhi_XXXX`. Conéctate con el móvil, entra a `http://192.168.4.1` y configura tu WiFi. Si no funciona, mantén pulsado **BOOT (GPIO 0)** al encender.

## Solución de problemas

### Pantalla blanca / no muestra nada
1. **Comprueba alimentación**: VCC a 3.3V, GND. BLK (backlight) a GPIO 3.
2. **Si tu pantalla tiene SCL y SDA al revés**: En `config.h` prueba intercambiar: `display_clk_pin = GPIO_NUM_10`, `display_mosi_pin = GPIO_NUM_9`
3. **Prueba en config.h**:
   - `DISPLAY_INVERT_COLOR false`
   - `DISPLAY_SWAP_XY true` (pantallas cuadradas 1.54")
   - `DISPLAY_OFFSET_X 40`, `DISPLAY_OFFSET_Y 40`
   - `DISPLAY_SPI_MODE 2` (en lugar de 3)
4. **¿Es otra pantalla?** Si es ILI9341 o ST7735, habría que cambiar el driver.

### Sin audio
- **MAX98357A pin SD**: Conecta SD del MAX98357A a **GPIO 21**. El firmware controla mute/unmute automáticamente (solo activa el altavoz al reproducir). Si SD está a GND o suelto = siempre mute.
- Comprueba: LRC→GPIO 16, BCLK→GPIO 15, DIN→GPIO 7
- Vin del MAX98357A: 3.7V de batería o 5V del convertidor
- Si no quieres usar control por GPIO, en `config.h` pon `audio_spk_sd_pin = GPIO_NUM_NC` y conecta SD del MAX98357A a 3.3V directamente

### No conecta a WiFi
- Asegúrate de estar en la red `XiaoZhi_XXXX` y acceder a `http://192.168.4.1`
- Si la red no aparece, mantén BOOT (GPIO 0) pulsado al encender
- Comprueba que tu WiFi sea 2.4 GHz (el ESP32-S3 no soporta 5 GHz)

### Solo funciona la cola / otros servos no se mueven
- **Alimentación**: Los 5 servos deben compartir el **mismo 5V y GND** del convertidor MT3608.
- Comprueba que los 4 servos (Antes, Izq, Der, Atrás) tengan: señal a su GPIO + 5V + GND.
- El MT3608 puede dar ~2A. 5 servos en movimiento pueden necesitar más: prueba con batería cargada.

## Notas

- **Batería**: Si tienes detección de carga (TC4056 STAT), configura `power_charge_detect_pin` en `config.h`
- **ADC batería**: Para nivel de batería, conecta un divisor de tensión a un pin ADC y configura `power_adc_unit` y `power_adc_channel` en `config.h`
- **Mapeo servos**: left_leg=Front, left_foot=Left, right_leg=Right, right_foot=Back, left_hand=Cola. El 6º servo (right_hand) no se usa.
