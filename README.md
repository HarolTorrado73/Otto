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

## Documentación

- [Conexiones y troubleshooting](main/boards/otto-robot-pet/README.md)
- [Changelog](CHANGELOG.md)
- [Guía de contribución](CONTRIBUTING.md)
- [Estrategia de commits](COMMITS.md)

## Licencia

MIT. Ver [LICENSE](LICENSE).

Basado en [xiaozhi-esp32](https://github.com/78/xiaozhi-esp32) por Shenzhen Xinzhi Future Technology Co., Ltd.
