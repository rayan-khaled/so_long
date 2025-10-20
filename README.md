# so_long 2D Game in C
A 2D MiniLibX game in C where you collect items and escape the map. Learn graphics, input handling, and clean coding.
This project introduces the fundamentals of graphical programming, event handling, and memory management in C.

## Features
- 2D top-down map using `.ber` files  
- Player movement (W, A, S, D)  
- Live movement counter displayed in the terminal  
- Map validation and error handling  
- Smooth window and event management  
- Clean exit handling via ESC or window close

## Map Rules
The map must contain:
- `1` → Wall  
- `0` → Empty space  
- `C` → Collectible  
- `E` → Exit  
- `P` → Player start position

Example:
111111
1P0C01
1E0001
111111

## Tech Stack
- **Language:** C  
- **Graphics Library:** MiniLibX  
- **Build System:** Makefile  

## Learning Goals
- Window and texture management  
- Keyboard input and event handling  
- Proper memory allocation and cleanup  
- Structuring clean and maintainable C code  

## Author
**Rayan Khaled**  
[rayannkhaled@outlook.com]
[rayan-khaled]
