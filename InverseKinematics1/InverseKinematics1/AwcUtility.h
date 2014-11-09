#ifndef AWCUTILITY_H_INCLUDED
#define AWCUTILITY_H_INCLUDED

#include <cmath>
#include "AwcVector2D.h"

float Approach( float Value, float Target, float Increment );
float Clamp( float Value, float Min, float Max);
float Pi();
float Deg2Rad(float Value);
float Rad2Deg(float Value);
float NormalizeAngle( float _ang );
float AngleDifference(float a, float b);
float ApproachAngle(float cur, float target, float inc);
Vector2D AngleForward(float _ang);

#endif // AWCUTILITY_H_INCLUDED
