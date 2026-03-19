# Estrategia de commits para Otto Robot Pet

Este documento describe cómo hacer commits lógicos y documentados para el repositorio.

## Orden sugerido de commits

### Commit 1: Licencia y atribución
```bash
git add LICENSE
git add CONTRIBUTING.md
git commit -m "docs: add LICENSE (MIT) and CONTRIBUTING guidelines"
```

### Commit 2: Documentación del proyecto
```bash
git add README.md
git add CHANGELOG.md
git add main/boards/otto-robot-pet/README.md
# README_zh.md y README_ja.md eliminados (solo español/inglés)
git commit -m "docs: project documentation for Otto Robot Pet"
```

### Commit 3: Limpieza de boards no usados
```bash
# Ejecutar primero: .\scripts\cleanup_boards.ps1
git add main/boards/
git add main/Kconfig.projbuild
git add scripts/cleanup_boards.ps1
git commit -m "refactor: remove unused boards, keep only otto-robot-pet"
```

### Commit 4: Simplificación de particiones
```bash
git add partitions/
git commit -m "chore: simplify partition tables for otto-robot-pet"
```

### Commit 5: Simplificación de documentación técnica
```bash
git add docs/
git commit -m "docs: keep only relevant technical documentation"
```

### Commit 6: CI/CD para otto-robot-pet
```bash
git add .github/
git commit -m "ci: configure GitHub Actions for otto-robot-pet build"
```

### Commit 7: Configuración del proyecto
```bash
git add CMakeLists.txt sdkconfig.defaults* .gitignore .clang-format
git commit -m "chore: project configuration and defaults"
```

### Commit 8: Código fuente principal
```bash
git add main/ scripts/
git commit -m "feat: Otto Robot Pet firmware based on xiaozhi-esp32"
```

---

## Notas

- Ajusta los mensajes según prefieras.
- Si un commit incluye muchos archivos, puedes dividirlo en subcommits.
- Usa `git status` para ver qué archivos están pendientes.
- Evita `git add .` — añade solo los archivos de cada grupo lógico.
