#ifndef CONFIG_H
#define CONFIG_H


class Config
{
    public:
        static Config& getConfig()
        {
            if (instance_ == NULL)
                instance_ = new Config();
            return instance_;
        };

        std::string getValue(std::string key)
        {
            if (storedConfig[key] != NULL)
                return storedConfig[key];
            else
                return ""
        }

    protected:
    private:
        Config(){};
        static Config *instance_;

        std::map<std::string,std::string> storedConfig;
};

#endif // CONFIG_H
