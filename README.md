# SDL2 Tetris Xbox

A NXDK / Xbox port of SDL2-Tetris

## Building

1. Install [NXDK](https://github.com/XboxDev/nxdk/wiki/Getting-Started)
2. `git clone https://github.com/chrisderwahre/sdl2-tetris-xbox.git`
3. `cd sdl2-tetris-xbox`
4. `make -f Makefile.nxdk`

## Controls

| Control    | Action               |
|------------|----------------------|
| DPad Left  | Move object to left  |
| DPad Right | Move object to right |
| DPad Down  | Soft object drop     |
| DPad Up    | Rotate object right  |
| A          | Hard object drop     |
| B          | Rotate right         |
| Y          | Hold object          |
| X          | Rotate left          |
| Back       | Pause                |
| Start      | Exit game            |


# SDL2 Tetris

A Tetris clone written in C. Most of the features from modern Tetris games
are implemented except for combos and special effects/nice graphics.

## How to Build

1. Make sure you have dependencies `SDL2` and `SDL2_ttf`
2. `git clone https://github.com/andwn/sdl2-tetris.git sdl2-tetris`
3. `cd sdl2-tetris`
4. `make`

## Controls

- Arrow left/right - Move left/right
- Arrow down - Soft Drop
- Space - Hard Drop
- Z - Rotate left (counter clockwise)
- X, Arrow up - Rotate right (clockwise)
- Shift - Hold
- Enter - Pause
