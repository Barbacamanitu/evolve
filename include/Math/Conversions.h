#ifndef CONVERSIONS_H
#define CONVERSIONS_H
#include <string>

namespace evolve
{

class Conversions
{
    public:
        static int StringToInt(std::string& str);

		static float RadiansToDegrees(float radians);
		static float DegreesToRadians(float degrees);
    protected:
    private:
};

}
#endif // CONVERSIONS_H
