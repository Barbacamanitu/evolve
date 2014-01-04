#ifndef EGEOMETRY_H
#define EGEOMETRY_H
#include "Vec2.h"
namespace evolve
{
class Geometry
{
public:
        static float InterpolateAngles(float oldAngle,float newAngle, float interpolation);
		static bool IsAngleInRange(float angle, float lower, float upper);
		static float DistanceBetweenAngles(float source, float target);
		static float GetClosestAngle(float target, float lowerLimit, float upperLimit);
		static Vec2 GetLineEndpoint(Vec2 origin, float angle, float length);
		static bool IsAngleClockwise(float origin, float target);
		static void MakeAnglePositive(float& angle);
		static double SimplifyAngle(double angle);
		static double GetTransformRotation(const sf::Transform& transform);
};
}
#endif

