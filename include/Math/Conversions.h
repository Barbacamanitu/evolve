#ifndef CONVERSIONS_H
#define CONVERSIONS_H
#include <string>
#include "Vec2.h"
namespace evolve
{

class Conversions
{
    public:
        static int StringToInt(std::string& str);

		static float RadiansToDegrees(float radians);
		static float DegreesToRadians(float degrees);
		static Vec2 DegreesToVector(float angle);
    protected:
    private:
};

}
#endif // CONVERSIONS_H
