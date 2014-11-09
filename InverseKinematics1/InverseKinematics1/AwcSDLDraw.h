/***********************************************************************
A library or so of functions that make rendering geometric primitives
easier with my 2D Vector system.
***********************************************************************/
#ifndef AWCSDLDRAW_H_INCLUDED
#define AWCSDLDRAW_H_INCLUDED

#include <math.h>

#include <SDL.h>

#include "AwcVector2D.h"
#include "AwcUtility.h"

extern SDL_Renderer* gRenderer;

void DrawPoint(Vector2D _pos);
void DrawLine(Vector2D _start, Vector2D _end);
void DrawCircle(Vector2D _pos, int _radius = 6, int _precis = 100);
void DrawCircleFill(Vector2D _pos, int _radius = 6, int _precis = 100);
void DrawQuad(Vector2D _start, Vector2D _end);
void DrawQuadCentered(Vector2D _center, int _vertical, int _horizontal);
void DrawQuadFill(Vector2D _start, Vector2D _end);
void DrawQuadFillCentered(Vector2D _center, float _vertical, float _horizontal);
/*
void DrawRect(Vector2D _start, Vector2D _end);
void DrawRectCentered(Vector2D _center, int _vertical, int _horizontal);
void DrawRectFill(Vector2D _start, Vector2D _end);
void DrawRectFillCentered(Vector2D _center, float _vertical, float _horizontal);
*/
#endif // AWCSDLDRAW_H_INCLUDED
