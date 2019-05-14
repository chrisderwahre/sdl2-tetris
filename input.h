#ifndef TETRIS_INPUT
#define TETRIS_INPUT

#ifdef NXDK
#include <SDL.h>
#include <hal/input.h>
#else
#include <SDL2/SDL.h>
#endif

// A couple structs that contain key/mouse button status
// There is a "current" state and an "old" state (previous frame)
struct {
	Uint8 up; Uint8 down; Uint8 left; Uint8 right;
	Uint8 z; Uint8 x; Uint8 shift; Uint8 space; Uint8 enter; Uint8 esc;
} key, oldKey;

// Updates the input structs to new values, and also handles SDL events
int input_update();

#endif
