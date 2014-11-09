#include "AwcUtility.h"

float Approach( float Value, float Target, float Increment )
{
    if( Value < Target)
    {
        if( (Value + Increment) < Target )
        {
            Value = Value + Increment;
        }
        else
        {
            Value = Target;
        }
    }
    else if( Value > Target)
    {
        if( (Value + Increment) > Target )
        {
            Value = Value - Increment;
        }
        else
        {
            Value = Target;
        }
    }
    else
    {
        Value = Target;
    }

    return Value;
}

float Clamp( float Value, float Min, float Max)
{
    if(Value > Max)
    {
        Value = Max;
    }
    else if(Value < Min)
    {
        Value = Min;
    }
    return Value;
}

float Pi()
{
    float Value = atan(1)*4;

    return Value;
}

float Deg2Rad(float Value)
{
    Value = (Value/180)*Pi();

    return Value;
}

float Rad2Deg(float Value)
{
    Value = ((Value*180)/(Pi()));

    return Value;
}

//05.10.14
float NormalizeAngle( float _ang )
{
	return fmod(( _ang + 180 ), 360) - 180;
}

float AngleDifference(float a, float b)
{
	float diff = NormalizeAngle( a - b );

	if(diff < 180)
	{
		return diff;
	}

	return diff - 360;
}

float ApproachAngle(float cur, float target, float inc)
{
	float diff = AngleDifference( target, cur );
	return Approach(cur, cur + diff, inc);
}

//sin and cos using degrees since cmath sin and cos use radians
float dsin(float _ang)
{
	return sin(Deg2Rad(_ang));
}

float dcos(float _ang)
{
	return cos(Deg2Rad(_ang));
}

Vector2D AngleForward(float _ang)
{
	return Vector2D(dcos(NormalizeAngle(_ang)), dsin(NormalizeAngle(_ang)));
}
