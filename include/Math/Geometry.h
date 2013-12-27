#ifndef EGEOMETRY_H
#define EGEOMETRY_H
namespace evolve
{
class Geometry
{
public:
        static float InterpolateAngles(float oldAngle,float newAngle, float interpolation);
		static bool IsAngleInRange(float angle, float lower, float upper);
		static float DistanceBetweenAngles(float source, float target);
};
}
#endif

