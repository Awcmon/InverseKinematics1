#include "AwcVector2D.h"

//Constructor
Vector2D::Vector2D()
{
	x = 0;
	y = 0;
}

Vector2D::Vector2D(float _x, float _y)
{
	x = _x;
	y = _y;
}

//Overloads
Vector2D Vector2D::operator+(const Vector2D &v)
{
	return Vector2D(x + v.x, y + v.y);
}

Vector2D Vector2D::operator-(const Vector2D &v)
{
	return Vector2D(x - v.x, y - v.y);
}

Vector2D Vector2D::operator*(float fl)
{
	return Vector2D(x * fl, y * fl);
}

Vector2D Vector2D::operator/(float fl)
{
	return Vector2D(x / fl, y / fl);
}

bool Vector2D::operator==(const Vector2D &v)
{
	return (v.x == x) && (v.y == y);
}

bool Vector2D::operator!=(const Vector2D &v)
{
	return (v.x != x) || (v.y != y);
}

std::ostream& operator<<(std::ostream& os, const Vector2D &v)
{
	os << "Vector2D( " << v.x << " , " << v.y << " )";
	return os;
}
//Funcs
float Vector2D::Length()
{
	return sqrt(x*x + y*y);
}

float Vector2D::LengthSqr()
{
	return (x*x + y*y);
}

Vector2D Vector2D::Normalized()
{
	float l = Length();
	if (l == 0.0f)
	{
		return Vector2D(0, 0);
	}

	return Vector2D(x,y)/l;
}

float Vector2D::Normalize()
{
	float l = Length();
	if (l == 0.0f)
	{
		x = 0;
		y = 0;
	}
	else
	{
		x /= l;
		y /= l;
	}

	return l;
}

float Vector2D::ToAngle()
{
	//If you're converting a vector to an angle, it's going to be a direction, so might as well normalize it.
//	Normalize();
	return Rad2Deg(atan2(y, x));
}

float Vector2D::DotProduct(Vector2D _v)
{
	return (x * _v.x + y * _v.y);
}

bool Vector2D::InBetween(Vector2D pos1, Vector2D pos2)
{
	if ((x >= pos1.x && x <= pos2.x) && (y >= pos1.y && y <= pos2.y))
	{
		return true;
	}
	else
	{
		return false;
	}
	return false;
}

//Global functions
float DotProduct(Vector2D _v1,Vector2D _v2)
{
	return (_v1.x * _v2.x + _v1.y * _v2.y);
}
