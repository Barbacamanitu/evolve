#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include <string>
#include <map>

class Configuration
{
    public:
        Configuration();
        virtual ~Configuration();
        template<typename T>
        T getValue(std::string key);
    protected:
    private:
        std::map<std::string,std::string> configData;
};

#endif // CONFIGURATION_H
