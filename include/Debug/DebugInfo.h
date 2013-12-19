#ifndef DEBUGINFO_H
#define DEBUGINFO_H

#include <SFML/Graphics.hpp>
class b2World;
class DebugInfo : public sf::Drawable
{
    public:
        DebugInfo();
        virtual ~DebugInfo();
        void draw(sf::RenderTarget & target, sf::RenderStates) const;
        void update(sf::RenderWindow & window);
        void updateFPS();
		void RenderJoints(sf::RenderTarget & target, sf::RenderStates states,b2World* world);
    protected:
    private:
        sf::Text debugText_;
        sf::Font debugFont_;
        sf::Clock mainClock_;
        int bodies;

        std::string getMouseString(sf::RenderWindow & window);
        std::string getFPSString();
        std::string getUPSString();

        void updateUPS();
        void clearTallies();
        void checkClock();

        int FPS;
        int frameTally;

        int updateTally;
        int UPS;

};

#endif // DEBUGINFO_H
