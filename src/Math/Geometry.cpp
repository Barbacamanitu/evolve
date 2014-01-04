#include "Geometry.h"
#include <cmath>
#include "Vec2.h"
#include "Conversions.h"
#define _USE_MATH_DEFINES
#include <math.h>
double evolve::Geometry::SimplifyAngle(double angle)
{
    angle =  fmod(angle,(2.0f * M_PI));
    if( angle < -M_PI )
        angle += (2.0f * M_PI);
    else if( angle >M_PI )
        angle -= (2.0f * M_PI);
    return angle;
}


double evolve::Geometry::GetTransformRotation(const sf::Transform& transform)
{
	const float* matrix = transform.getMatrix();
	double cos = matrix[0];
	double sin = matrix[1];
	//Now we have the sin and cos of the angle. convert to radians.
	//sin = x distance
	//cos = y distance

	//rad is the angle. tan(rad) = cos/sin
	double rad = atan(cos/sin);
	return rad;
	
}

float evolve::Geometry::InterpolateAngles(float oldAngle,float newAngle, float interpolation)
{
     float difference = std::abs(newAngle - oldAngle);
        if (difference > 180)
        {
            if (newAngle > oldAngle)
            {
                oldAngle += 360;
            }
            else
            {
                newAngle += 360;
            }
        }

        // Interpolate it.
        float value = (oldAngle + ((newAngle - oldAngle) * interpolation));

        // Wrap it..
        float rangeZero = 360;

        if (value >= 0 && value <= 360)
           return value;
        else
        return (int)(value) % 360;

}

bool evolve::Geometry::IsAngleInRange(float angle, float lower, float upper)
{
	float centerAngle = InterpolateAngles(lower,upper,.5f);
	float disFromCenter = DistanceBetweenAngles(centerAngle,angle);
	float range = DistanceBetweenAngles(lower,upper);
	return (disFromCenter < (range/2.f));

}

void evolve::Geometry::MakeAnglePositive(float& angle)
{
	while(angle < 0)
		angle += 360;
	while (angle> 360)
		angle-=360;
}

bool evolve::Geometry::IsAngleClockwise(float origin, float target)
{
	return false;
}

float evolve::Geometry::DistanceBetweenAngles(float source, float target)
{
	return 180.0 - std::fabs(std::fmod(std::fabs(source - target), 360.0) - 180.0);
}

float evolve::Geometry::GetClosestAngle(float target, float lowerLimit, float upperLimit)
{
	if (IsAngleInRange(target,lowerLimit,upperLimit))
		return target;
	
	float lD = DistanceBetweenAngles(target,lowerLimit);
	float uD = DistanceBetweenAngles(target,upperLimit);
	return (lD < uD) ? lowerLimit : upperLimit;

}

evolve::Vec2 evolve::Geometry::GetLineEndpoint(Vec2 origin, float angle, float length)
{
	evolve::Vec2 dirVector = evolve::Conversions::DegreesToVector(angle);
	return origin + (dirVector * length);
}
