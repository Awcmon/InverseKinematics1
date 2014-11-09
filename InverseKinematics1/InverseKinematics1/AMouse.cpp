#include "AMouse.h"

extern SDL_Event e;

AMouse::AMouse()
{
	m1down = false;
	m1downCont = false;
	m1up = false;
	m1upCont = false;
}


AMouse::~AMouse()
{
}

void AMouse::think()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	pos = Vector2D(x, y);

	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		m1up = false;
		m1upCont = false;
		m1isDown = true;
		if (!m1downCont)
		{
			m1down = true;
			downPos = Vector2D(x, y);
			m1downCont = true;
		}
		else
		{
			m1down = false;
		}
	}
	else
	{
		m1down = false;
		m1downCont = false;
		m1isDown = false;
		if (!m1upCont)
		{
			m1up = true;
			upPos = Vector2D(x, y);
			m1upCont = true;
		}
		else
		{
			m1up = false;
		}
	}

	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
	{
		m2up = false;
		m2upCont = false;
		m2isDown = true;
		if (!m2downCont)
		{
			m2down = true;
			downPos = Vector2D(x, y);
			m2downCont = true;
		}
		else
		{
			m2down = false;
		}
	}
	else
	{
		m2down = false;
		m2downCont = false;
		m2isDown = false;
		if (!m2upCont)
		{
			m2up = true;
			upPos = Vector2D(x, y);
			m2upCont = true;
		}
		else
		{
			m2up = false;
		}
	}
}
