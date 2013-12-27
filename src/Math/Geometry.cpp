#include "Geometry.h"
#include <cmath>
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

float evolve::Geometry::DistanceBetweenAngles(float source, float target)
{
	return 180.0 - std::fabs(std::fmod(std::fabs(source - target), 360.0) - 180.0);
}
