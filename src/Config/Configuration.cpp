#include "Configuration.h"
#include <string>
#include <Math/Conversions.h>
Configuration::Configuration()
{
    //ctor
}

Configuration::~Configuration()
{
    //dtor
}

template <typename T>
T Configuration::getValue(std::string key)
{
    try
    {
        return boost::lexical_cast<T>(configData[key]);
    }
    catch(...)
    {
        return boost::lexical_cast<T>(-1);
    }

}

template<>
int Configuration::getValue(std::string key)
{
    //Return Int
    return Math::Conversions::StringToInt(key);
}
