#pragma once
//#define self this
#include <SDL.h>
#include "AwcVector2D.h"
#include "AMouse.h"
#include <string>

extern SDL_Event e;

extern SDL_Renderer* gRenderer;

const int RENDER_WIDTH = 800;
const int RENDER_HEIGHT = 600;

extern unsigned gPoints;

extern AMouse mouse;
