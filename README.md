# Otto Robot Pet - Firmware XiaoZhi AI

Robot mascota (gato/perro) con servo en la cola, basado en [xiaozhi-esp32](https://github.com/78/xiaozhi-esp32) y XiaoZhi AI.

## Características

- **Voz**: Reconocimiento de palabra de activación, ASR + LLM + TTS
- **Pantalla**: ST7789 240x240 con emojis y emociones
- **Audio**: MAX98357A (I2S) + INMP441 (micrófono)
- **Servos**: 5x MG90S (Antes, Izq, Der, Atrás, Cola)
- **Control**: WebSocket para control remoto
- **Servidor**: [xiaozhi.me](https://xiaozhi.me) (cuenta gratuita)

## Hardware

| Componente | Especificación |
|------------|----------------|
| MCU | ESP32-S3 (16 MB flash) |
| Pantalla | ST7789 240x240 SPI |
| Altavoz | MAX98357A I2S |
| Micrófono | INMP441 I2S |
| Servos | 5x MG90S |
| Alimentación | Batería 3.7V → TC4056 → MT3608 (5V) |

## Requisitos

- **ESP-IDF** v5.4 o superior ([instalación](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/get-started/))
- **Python** 3.8+

Abre **ESP-IDF Command Prompt** (Windows) o terminal con `source $IDF_PATH/export.sh` (Linux/macOS) antes de ejecutar los comandos.

## Compilación

```bash
python scripts/release.py otto-robot-pet
```

O manualmente:

```bash
idf.py set-target esp32s3
idf.py menuconfig  # Xiaozhi Assistant → Board Type → Otto Robot Pet
idf.py build flash monitor
```

## Flasheo

```bash
idf.py -p COM4 flash monitor
```

Sustituye `COM4` por tu puerto serial.

## Configuración WiFi (ESP32-S3)

Al encender el robot por primera vez, el ESP32-S3 crea un **punto de acceso WiFi** llamado `XiaoZhi_XXXX`. Pasos:

1. Conecta tu móvil o PC a la red `XiaoZhi_XXXX`
2. Se abrirá automáticamente una página web (o entra a `http://192.168.4.1`)
3. Selecciona tu red WiFi doméstica e introduce la contraseña
4. El robot se conectará y reiniciará

Si no se abre la página, mantén pulsado el **botón BOOT (GPIO 0)** al encender para entrar en modo configuración WiFi.

## Configuración del agente (xiaozhi.me)

Tras activar el dispositivo con el código que aparece en pantalla, configura la personalidad del robot en la consola:

- **Consola**: [xiaozhi.me/console](https://xiaozhi.me/console)
- **Agentes** → tu agente → **Configurar rol**: nombre, idioma, voz, personalidad
- **Agregar dispositivo**: vincula el Otto Robot Pet al agente

La URL de configuración de cada agente es única (ej: `xiaozhi.me/console/agents/XXXX/config`). Puedes crear tu propio agente o usar uno existente.

## Documentación

- [Conexiones y troubleshooting](main/boards/otto-robot-pet/README.md)
- [Changelog](CHANGELOG.md)
- [Guía de contribución](CONTRIBUTING.md)
- [Estrategia de commits](COMMITS.md)

## Licencia

MIT. Ver [LICENSE](LICENSE).

Basado en [xiaozhi-esp32](https://github.com/78/xiaozhi-esp32) por Shenzhen Xinzhi Future Technology Co., Ltd.
