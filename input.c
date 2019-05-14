#include "input.h"

#ifndef NXDK
const int K_LEFT   = SDL_SCANCODE_LEFT;
const int K_RIGHT  = SDL_SCANCODE_RIGHT;
const int K_UP     = SDL_SCANCODE_UP;
const int K_DOWN   = SDL_SCANCODE_DOWN;
const int K_Z      = SDL_SCANCODE_Z;
const int K_X      = SDL_SCANCODE_X;
const int K_SHIFT  = SDL_SCANCODE_LSHIFT;
const int K_SPACE  = SDL_SCANCODE_SPACE;
const int K_RETURN = SDL_SCANCODE_RETURN;
const int K_ESC    = SDL_SCANCODE_ESCAPE;

#else

const int K_LEFT   = XPAD_DPAD_LEFT;
const int K_RIGHT  = XPAD_DPAD_RIGHT;
const int K_UP     = XPAD_DPAD_UP;
const int K_DOWN   = XPAD_DPAD_DOWN;
const int K_Z      = XPAD_X;
const int K_X      = XPAD_B;
const int K_SHIFT  = XPAD_Y;
const int K_SPACE  = XPAD_A;
const int K_RETURN = XPAD_BACK;
const int K_ESC    = XPAD_START;

Uint8 getAnalogButton(XPAD_INPUT *gPad, int button) {
  return gPad->CurrentButtons.ucAnalogButtons[button];
}

Uint8 getDigitalButton(XPAD_INPUT *gPad, int button) {
  return gPad->CurrentButtons.usDigitalButtons & button;
}
#endif

int input_update() {
	SDL_Event event;
	while(SDL_PollEvent(&event)) {
		if(event.type == SDL_QUIT) return 1;
	}
	oldKey.left = key.left;
	oldKey.right = key.right;
	oldKey.up = key.up;
	oldKey.down = key.down;
	oldKey.z = key.z;
	oldKey.x = key.x;
	oldKey.shift = key.shift;
	oldKey.space = key.space;
	oldKey.enter = key.enter;
	oldKey.esc = key.esc;
#ifndef NXDK
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	key.up = state[K_UP];
	key.down = state[K_DOWN];
	key.left = state[K_LEFT];
	key.right = state[K_RIGHT];
	key.z = state[K_Z];
	key.x = state[K_X];
	key.shift = state[K_SHIFT];
	key.space = state[K_SPACE];
	key.enter = state[K_RETURN];
	key.esc = state[K_ESC];
#else
        XInput_GetEvents();
        key.up = getDigitalButton(&g_Pads[0], K_UP);
        key.down = getDigitalButton(&g_Pads[0], K_DOWN);
        key.left = getDigitalButton(&g_Pads[0], K_LEFT);
        key.right = getDigitalButton(&g_Pads[0], K_RIGHT);
        key.z = getAnalogButton(&g_Pads[0], K_Z);
        key.x = getAnalogButton(&g_Pads[0], K_X);
        key.shift = getAnalogButton(&g_Pads[0], K_SHIFT);
        key.space = getAnalogButton(&g_Pads[0], K_SPACE);
        key.enter = getDigitalButton(&g_Pads[0], K_RETURN);
        key.esc = getDigitalButton(&g_Pads[0], K_ESC);
#endif
	return 0;
}
