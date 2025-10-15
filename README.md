# FdF - Fil de Fer
<img width="1279" height="719" alt="fdf" src="https://github.com/user-attachments/assets/45b90f81-54b7-4af0-9ce3-bcd343670f3b" />

## About
This project is about creating a simple wireframe model representation of a 3D landscape by linking various points (x, y, z) with line segments (edges). The points are read from a .fdf file, which contains a Z-value (and a color in hexadecimal notation) for each grid-point.

### Concepts
- X Window System
- Raster Graphics
- Line Drawing Algorithms
- Vectors (Math)
- Transformation Matrices
- 3D Projection

## Installation

### Dependencies
MiniLibX for Linux requires xorg, x11 and zlib, therefore you will need to install the following dependencies: `xorg`, `libxext-dev`, `zlib1g-dev` and `libbsd-dev`.
For Debian/Ubuntu-based distros, run:
```sh
sudo apt update && sudo apt install xorg libxext-dev zlib1g-dev libbsd-dev
```

### Main Program
Clone the repository:
```sh
git clone https://github.com/Breno-S/42_FdF.git
```
Inside the project's directory, build the program:
```sh
make bonus
```

## Usage
Call the executable and pass the path to the fdf map as its argument:
```
./fdf maps/42.fdf

```

### Controls

#### Mandatory
| Key                              | Action | 
| -------------------------------- | ------ |
| Mouse-Wheel Up, Mouse-Wheel Down | Zoom |
| ESC                              | Close window |

#### Bonus
| Key                              | Action |
| -------------------------------- | ------- |
| Mouse-Wheel Up, Mouse-Wheel Down | Zoom |
| W, A, S, D                       | Move |
| Q, E                             | Rotate around Z-axis |
| Numpad 2, Numpad 8               | Rotate around X-axis |
| Numpad 4, Numpad 6               | Rotate around Y-axis |
| Numpad 5                         | Reset model orientation and position |
| +                                | Increase Z scaling factor |
| -                                | Decrease Z scaling factor |
| 0                                | Reset Z scaling factor |
| ESC                              | Close window |
