#ifndef AWCVECTOR2_H_INCLUDED
#define AWCVECTOR2_H_INCLUDED

#include <math.h>
#include <iostream>
//#include "AwcUtility.h"

extern float Rad2Deg(float Value);

class Vector2D
{
public:
	float x, y;
	//Constructor
	Vector2D::Vector2D();
	Vector2D(float _x, float _y);
	//Overloads
	Vector2D operator+(const Vector2D &v);
	Vector2D operator-(const Vector2D &v);
	Vector2D operator*(float fl);
	Vector2D operator/(float fl);
	bool operator==(const Vector2D &v);
	bool operator!=(const Vector2D &v);
	friend std::ostream& operator<<(std::ostream& os, const Vector2D &v);
	//Funcs
	float Length();
	float LengthSqr();
	Vector2D Normalized();
	float Normalize();
	float ToAngle();
	float DotProduct(Vector2D _v);
	bool InBetween(Vector2D pos1, Vector2D pos2);
};

float DotProduct(Vector2D _v1, Vector2D _v2);

#endif // AWCVECTOR2_H_INCLUDED
