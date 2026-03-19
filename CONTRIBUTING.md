# Guía de contribución

## Otto Robot Pet - Proyecto basado en xiaozhi-esp32

Este proyecto es un fork adaptado para el **Otto Robot Pet** (robot gato/perro con servo en la cola).

### Requisitos

- ESP-IDF v5.4 o superior
- Python 3.8+
- Board: ESP32-S3 con 16 MB flash

### Compilación

```bash
python scripts/release.py otto-robot-pet
```

O manualmente:

```bash
idf.py set-target esp32s3
idf.py menuconfig  # Xiaozhi Assistant → Board Type → Otto Robot Pet
idf.py build flash monitor
```

### Estilo de código

- Usar formato de código del proyecto (`.clang-format`)
- Mensajes de commit claros y descriptivos
- Documentar cambios en hardware o pines en `main/boards/otto-robot-pet/README.md`

### Reportar problemas

Incluir:
- Versión del firmware
- Descripción del hardware (pantalla, audio, servos)
- Logs del monitor serial si aplica
