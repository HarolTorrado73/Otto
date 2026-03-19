# Changelog

Todos los cambios notables de este proyecto se documentan en este archivo.

El formato está basado en [Keep a Changelog](https://keepachangelog.com/es-ES/1.0.0/).

## [2.2.4] - 2025-03

### Añadido

- Board **Otto Robot Pet** para robot gato/perro con servo en cola
- Soporte para pantalla ST7789 (240x240)
- Audio: MAX98357A (I2S) + INMP441 (micrófono)
- Control de pin SD del MAX98357A por GPIO (mute/unmute automático)
- 5 servos MG90S (Antes, Izq, Der, Atrás, Cola)
- WebSocket control server para control remoto
- Emojis y display de emociones en pantalla

### Basado en

- [xiaozhi-esp32](https://github.com/78/xiaozhi-esp32) v2.2.4
- Framework XiaoZhi AI (ASR + LLM + TTS)
