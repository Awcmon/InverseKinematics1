//Using SDL and standard IO
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include <stdlib.h>
#include <stdio.h>
#include <cmath>

#include "Globals.h"
#include "LWindow.h"

#include "AMouse.h"
#include "AwcVector2D.h"
#include "AwcUtility.h"
#include "AwcSDLDraw.h"

//Globals--------------------------------------------
//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

LWindow gWindow;
SDL_Renderer* gRenderer = NULL;

SDL_Event e;

AMouse mouse;
//---------------------------------------------------

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow.init();
	}

	return success;
}

void close()
{
	//Destroy window
	gWindow.free();
	gRenderer = NULL;
	SDL_Quit();
}

float cosinesLaw(float a, float b, float c)
{
	return acos( ((a*a) + (b*b) - (c*c)) / (2*a*b) );
}

//------------------------------------------------------------------------
int main(int argc, char* argv[])
{
	init();

	gRenderer = gWindow.mRenderer;

	float angA, angB, angC, angD;
	float A = 200;
	float B = 200;
	Vector2D pos1(400, 300);

	bool run = true;
	while (run)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				run = false;
			}
			//formerly static void key_func ( unsigned char key, int x, int y )
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_c:
					
					break;
				case SDLK_q:
					run = false;
					break;
				case SDLK_v:
					
					break;
				}
			}
		}

		mouse.think();


		float L = (mouse.pos - pos1).Length();

		angA = Rad2Deg(cosinesLaw(A, L, B));
		angB = Rad2Deg(cosinesLaw(A, B, L));
		angC = (mouse.pos - pos1).ToAngle() - angA;
		angD = (180 - angB + angC);

		printf("A: %f\n", A);
		printf("B: %f\n", B);
		printf("L: %f\n", L);

		printf("AngA: %f\n", angA);
		printf("AngB: %f\n", angB);
		printf("AngC: %f\n", angC);
		printf("AngD: %f\n", angD);

		Vector2D pos2 = pos1 + AngleForward(angC)*A;
		Vector2D pos3 = pos2 + AngleForward(angD)*B;

		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0xFF);
		SDL_RenderSetLogicalSize(gRenderer, RENDER_WIDTH, RENDER_HEIGHT);
		SDL_RenderClear(gRenderer);

		DrawQuadFill(Vector2D(0, 0), Vector2D(512, 512));

		SDL_SetRenderDrawColor(gRenderer, 0, 0xFF, 0, 0xFF);
		//flying crazy ik arms
		DrawLine(pos1, pos2);
		DrawLine(pos2, pos3);

		//body
		DrawLine(pos1 + Vector2D(0, 1) * 150, pos1 + Vector2D(0, 1) * -50);
		DrawCircle(pos1 + Vector2D(0, 1) * -110, 60, 420);
		DrawLine(pos1, pos1 + Vector2D(1, 1).Normalized() * 100);
		DrawLine(pos1 + Vector2D(1, 1).Normalized() * 100, pos1 + Vector2D(1, 1).Normalized() * 100 + Vector2D(0, 1).Normalized() * 100);
		DrawLine(pos1 + Vector2D(0, 1) * 150, pos1 + Vector2D(0, 1) * 150 + Vector2D(1, 1).Normalized() * 150);
		DrawLine(pos1 + Vector2D(0, 1) * 150, pos1 + Vector2D(0, 1) * 150 + AngleForward(-45) * -150);
		//Face
		DrawCircle(pos1 + Vector2D(0, 1) * -130 + Vector2D(1, 0) * 30, 10, 50);
		DrawCircle(pos1 + Vector2D(0, 1) * -130 + Vector2D(1, 0) * -30, 10, 50);
		DrawLine(pos1 + Vector2D(0, 1) * -80 + Vector2D(1, 0) * -30, pos1 + Vector2D(0, 1) * -80 + Vector2D(1, 0) * 30);

		SDL_RenderPresent(gRenderer);
	}

	close();

	return 0;
}
