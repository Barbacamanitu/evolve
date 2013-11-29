 #include "DebugInfo.h"

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
