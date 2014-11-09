#include "AwcSDLDraw.h"

void DrawPoint(Vector2D pos)
{
	SDL_RenderDrawPoint(gRenderer, pos.x, pos.y);
}

void DrawLine(Vector2D start, Vector2D end)
{
	SDL_RenderDrawLine(gRenderer, start.x, start.y, end.x, end.y);
}

void DrawCircle(Vector2D pos, int radius, int precis)
{
	for (int i = 0; i < precis; i++)
	{
		SDL_RenderDrawPoint(gRenderer, (pos.x - cos(((2 * Pi()) / precis)*i)*radius), (pos.y - sin(((2 * Pi()) / precis)*i)*radius));
	}
}

void DrawCircleFill(Vector2D pos, int radius, int precis)
{
	for (int i = 0; i < precis; i++)
	{
		SDL_RenderDrawLine(gRenderer, pos.x, pos.y, (pos.x - cos(((2 * Pi()) / precis)*i)*radius), (pos.y - sin(((2 * Pi()) / precis)*i)*radius));
	}
}

void DrawQuad(Vector2D _start, Vector2D _dim)
{
	SDL_Rect outlineRect = { _start.x, _start.y, _dim.x, _dim.y };
	SDL_RenderDrawRect(gRenderer, &outlineRect);
}

void DrawQuadCentered(Vector2D _center, int _vertical, int _horizontal)
{
	SDL_Rect outlineRect = { _center.x - _horizontal, _center.y - _vertical, _horizontal * 2, _vertical * 2 };
	SDL_RenderDrawRect(gRenderer, &outlineRect);
}

void DrawQuadFill(Vector2D _start, Vector2D _dim)
{
	SDL_Rect fillRect = { _start.x, _start.y, _dim.x, _dim.y };
	SDL_RenderFillRect(gRenderer, &fillRect);
}

void DrawQuadFillCentered(Vector2D _center, float _vertical, float _horizontal)
{
	SDL_Rect fillRect = { _center.x - _horizontal, _center.y - _vertical, _horizontal * 2, _vertical * 2 };
	SDL_RenderFillRect(gRenderer, &fillRect);
}
/*
void DrawRect(Vector2D start, Vector2D end)
{
	SDL_Rect outlineRect = { start.x, start.y, end.x, end.y };
	SDL_RenderDrawRect(gRenderer, &outlineRect);
}

void DrawRectCentered(Vector2D center, int vertical, int horizontal)
{
	SDL_Rect outlineRect = { center.x - horizontal, center.y - vertical, horizontal * 2, vertical * 2 };
	SDL_RenderDrawRect(gRenderer, &outlineRect);
}

void DrawRectFill(Vector2D start, Vector2D end)
{
	SDL_Rect fillRect = { start.x, start.y, end.x, end.y };
	SDL_RenderFillRect(gRenderer, &fillRect);
}

void DrawRectFillCentered(Vector2D center, float vertical, float horizontal)
{
	SDL_Rect fillRect = { center.x - horizontal, center.y - vertical, horizontal*2, vertical*2 };
	SDL_RenderFillRect(gRenderer, &fillRect);
}
*/