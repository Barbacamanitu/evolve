#include <Debug/DebugInfo.h>
#include <stdio.h>
#include <Box2D\Box2D.h>
DebugInfo::DebugInfo()
{
    //ctor
    debugFont_.loadFromFile("sansation.ttf");
    debugText_.setFont(debugFont_);
    debugText_.setCharacterSize(18);
    debugText_.setColor(sf::Color::Green);
    debugText_.setStyle(sf::Text::Bold);

    mainClock_.restart();

    FPS = 1;
}

DebugInfo::~DebugInfo()
{
    //dtor
}

void DebugInfo::update( sf::RenderWindow& window)
{
    updateUPS();
    debugText_.setString(getMouseString(window)+  "\n" + getFPSString() + "\n" + getUPSString());
    checkClock();

}

void DebugInfo::updateFPS()
{
    frameTally++;
}

void DebugInfo::updateUPS()
{
    updateTally++;
}

void DebugInfo::checkClock()
{
    int interval = 1;
    if (mainClock_.getElapsedTime().asSeconds() > interval)
        clearTallies();
}
void DebugInfo::clearTallies()
{
    float seconds = mainClock_.restart().asSeconds();
    FPS = (int)(frameTally / seconds);
    UPS = (int)(updateTally / seconds);

    frameTally = 0;
    updateTally = 0;
}



std::string DebugInfo::getMouseString(sf::RenderWindow & window)
{
    sf::Vector2i mPos = sf::Mouse::getPosition(window);
    char buffer[50];
    sprintf(buffer,"X: %d,Y: %d",mPos.x,mPos.y);
    std::string mPosStr(buffer);
    return mPosStr;
}

std::string DebugInfo::getFPSString()
{
    char buf[50];
    sprintf(buf,"FPS: %d",FPS);
    std::string fpsStr(buf);
    return fpsStr;
}

std::string DebugInfo::getUPSString()
{
    char buf[50];
    sprintf(buf,"UPS: %d",UPS);
    std::string fpsStr(buf);
    return fpsStr;
}

void DebugInfo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(debugText_,states);
}

void DebugInfo::RenderJoints(sf::RenderTarget & target, sf::RenderStates states,b2World* world)
{
	float rad = .1f;
	sf::CircleShape circle;
	circle.setRadius(rad);
	circle.setOrigin(rad,rad);
	std::vector<sf::Color> colors;
	colors.push_back(sf::Color::White);
	colors.push_back(sf::Color::Green);
	colors.push_back(sf::Color::Yellow);
	colors.push_back(sf::Color::Cyan);

	




	/*b2Body* joints = world->GetBodyList();
	for (int i = 0; i < world->GetBodyCount()-1; i++)
	{
		int cI = i % colors.size();
		circle.setFillColor(colors[cI]);

		joints[i].ApplyTorque(((rand() % 10) - 5) * .5f,false);

		//b2Vec2 jPosB = joints[i].GetAnchorB();
		

		///circle.setPosition(jPosA.x,jPosA.y);
		target.draw(circle,states);
		//circle.setPosition(jPosB.x,jPosB.y);
	
		target.draw(circle,states);

		

	}*/
}
