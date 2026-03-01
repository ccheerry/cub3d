# 🎮 cub3D

<div align="center">

**Un motor de raycasting 3D inspirado en los clásicos juegos FPS de los 90s**

[![42 School Project](https://img.shields.io/badge/42-Project-00babc?style=flat-square&logo=42)](https://www.42madrid.com/)
[![Made with C](https://img.shields.io/badge/Made%20with-C-A8B9CC?style=flat-square&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![MiniLibX](https://img.shields.io/badge/Graphics-MiniLibX-orange?style=flat-square)](https://github.com/42Paris/minilibx-linux)

> 🕹️ Un proyecto de 42 que combina matemáticas, gráficos y C para crear tu propio motor 3D.

---

[🎮 Vista Previa](#-vista-previa) •  [🔍 Raycasting](#-qué-es-el-raycasting) • [🛠️ Técnicas](#-técnicas-implementadas) • [📦 Instalación](#-instalación) • [🎮 Uso](#-uso) • [🗺️ Mapa](#-formato-de-mapa) • [🏗️ Arquitectura](#-arquitectura-del-proyecto) • [👥 Autores](#-autores)
</div>

---

## 📖 Descripción del Proyecto

**cub3D** propone recrear un motor de renderizado 3D similar al clásico **Wolfenstein 3D** (1992), utilizando la técnica de **raycasting**. El objetivo es explorar los fundamentos de los gráficos por computadora, matemáticas vectoriales, y programación de bajo nivel en C.

El jugador navega por un laberinto renderizado en pseudo-3D, con texturas en las paredes, colores personalizables para techo y suelo, y controles fluidos de movimiento y rotación.

## ✅ Nota final

![Grade](https://i.imgur.com/LQRaa4H.png "Grade")

---

## 🎮 Vista Previa

![Gameplay](demo/game.gif)

---

## ✨ Características Principales

### Funcionalidades Básicas
- 🎯 **Renderizado en tiempo real** con raycasting
- 🧱 **Texturas diferentes** para cada orientación de pared (Norte, Sur, Este, Oeste)
- 🎨 **Colores personalizables** para techo y suelo
- 🕹️ **Controles suaves**: WASD para movimiento, flechas para rotación
- 🗺️ **Sistema de parseo de mapas** desde archivos `.cub`
- 🚪 **Detección de colisiones** con paredes

### Bonus Implementados
- 🎬 **Sistema de sprites animados** (enemigos)
- 🚪 **Puertas interactivas** que se abren/cierran
- 🗺️ **Minimapa en tiempo real**
- 🖱️ **Control de cámara con ratón**
- 🧱 **Colisiones de pared**

---

## 🔍 ¿Qué es el Raycasting?

El **raycasting** es una técnica de renderizado 3D popularizada por juegos como Wolfenstein 3D y el primer DOOM. A diferencia del renderizado 3D completo, el raycasting es una técnica 2.5D que:

### Principio Básico
1. **Proyección de rayos**: Por cada columna vertical de la pantalla, se lanza un rayo desde la posición del jugador
2. **Intersección**: Se calcula dónde intersecta el rayo con las paredes del mapa
3. **Altura de pared**: La distancia al punto de intersección determina la altura de la pared a dibujar
4. **Texturizado**: Se mapea la textura correspondiente según la orientación de la pared

### Ventajas
- ⚡ **Rendimiento eficiente** en comparación con renderizado 3D completo
- 🎯 **Matemáticas simplificadas** (principalmente trigonometría 2D)
- 💾 **Menor uso de memoria** al trabajar con mapas 2D

### Algoritmo DDA (Digital Differential Analysis)
El proyecto utiliza el **algoritmo DDA** para determinar las intersecciones rayo-pared de forma eficiente, avanzando paso a paso por la cuadrícula del mapa hasta encontrar una colisión.

---

## 🛠️ Técnicas Implementadas

### Renderizado y Geometría
- **Plano de cámara**: Método de proyección usando vectores dirección y plano de cámara perpendicular
- **Corrección de distorsión fish-eye**: Uso de distancia perpendicular en lugar de distancia euclidiana
- **Z-buffering**: Buffer de profundidad para renderizado correcto de sprites
- **Cálculo de intersecciones**: Algoritmo DDA optimizado para detección de colisiones

### Sistema de Texturas
- **Mapeo UV**: Conversión de coordenadas mundo a coordenadas de textura
- **Shading direccional**: Oscurecimiento de paredes según orientación (mayor realismo)
- **Sampling de píxeles**: Interpolación lineal para escalar texturas

### Física y Colisión
- **Sliding collision**: El jugador "desliza" contra las paredes en lugar de detenerse bruscamente
- **Radio de colisión**: Sistema de colisión circular alrededor del jugador
- **Detección predictiva**: Verificación de colisiones antes del movimiento

### Estructura de Datos
- **Sistema de vectores dinámicos**: El mapa se almacena usando una estructura de vector personalizada (`t_vec`) que permite gestionar dinámicamente las filas del grid
- **Strings tipados**: Cada fila del mapa se representa como un `t_string` que almacena los caracteres y su longitud

---

## 📦 Instalación

### Requisitos Previos
```bash
# En sistemas basados en Debian/Ubuntu
sudo apt-get update
sudo apt-get install gcc make xorg libxext-dev libbsd-dev libxfixes-dev
```

### Compilación
```bash
# Clonar el repositorio
git clone https://github.com/ccheerry/cub3d.git
cd cub3d

# Compilar el proyecto
make

# El ejecutable 'cub3D' se generará en el directorio raíz
```

---

## 🎮 Uso

### Ejecutar el Juego
```bash
./cub3D maps/map.cub
```

### Controles

| Tecla | Acción |
|-------|--------|
| `W` | Avanzar |
| `S` | Retroceder |
| `A` | Moverse a la izquierda |
| `D` | Moverse a la derecha |
| `←` / `→` | Rotar cámara |
| `ESC` | Salir del juego |
| **Ratón** | Control de cámara (bonus) |

---

## 🗺️ Formato de Mapa

Los mapas se definen en archivos `.cub` con el siguiente formato:

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

### Elementos del Mapa
- `1` = Pared
- `0` = Espacio vacío
- `N/S/E/W` = Posición inicial del jugador y orientación
- `X` = Enemigo (bonus)
- `D` = Puerta (bonus)

### Configuración
- `NO/SO/WE/EA` = Rutas a texturas de paredes
- `F` = Color RGB del suelo (0-255)
- `C` = Color RGB del techo (0-255)

---

## 🏗️ Arquitectura del Proyecto

```
cub3D/
├── include/
│   ├── cub3d.h          # Definiciones principales
├── src/
│   ├── core/            # Inicialización y loop principal
│   ├── map/             # Parseo y validación de mapas
│   ├── render/          # Motor de raycasting y texturas
│   ├── input/           # Manejo de eventos y controles
│   └── bonus/           # Sprites, minimapa, puertas, mouse
├── libft/               # Librería de funciones
├── mlx/                 # MiniLibX (Librería gráfica)
├── maps/                # Mapas de ejemplo
├── textures/            # Archivos .xpm de texturas
└── Makefile
```

---

## 👥 Autores

Desarrollado como proyecto de **42 Madrid**

- [@ccheerry](https://github.com/ccheerry)
- [@Albertiito13](https://github.com/Albertiito13)

---
