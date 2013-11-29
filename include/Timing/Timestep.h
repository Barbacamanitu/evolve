#ifndef TIMESTEP_H
#define TIMESTEP_H

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

class Timestep
{
    public:
        float TIMESTEP;
        Timestep();
        virtual ~Timestep();
        void startLoop();
        bool canUpdate();
        float getAlpha();
    protected:
    private:
        sf::Clock mClock;
        float accumulator;
        float sinceLastUpdate;
        int frameSkip;


};

#endif // TIMESTEP_H
