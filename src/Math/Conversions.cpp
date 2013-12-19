#include "Conversions.h"
int evolve::Conversions::StringToInt(std::string& str)
{
    return 1;
}

float evolve::Conversions::RadiansToDegrees(float radians)
{
	float angle = (180/ 3.141592653589793f) * radians;
	while (angle <= 0)  angle += 360;
	while (angle > 360) angle -= 360;
	return angle;
}

float evolve::Conversions::DegreesToRadians(float degrees)
{
	while (degrees <= 0)  degrees += 360;
	while (degrees > 360) degrees -= 360;
	return (3.141592653589793f/180) * degrees;
}