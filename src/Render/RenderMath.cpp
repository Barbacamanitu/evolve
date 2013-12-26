#include <Render\RenderMath.h>
#include <Math\eMath.h>
RenderMath::RenderMath()
{
    //ctor
}

RenderMath::~RenderMath()
{
    //dtor
}

sf::Transform RenderMath::InterpolateTransforms(sf::Vector2f oldPosition, sf::Vector2f newPosition, float oldAngle, float newAngle, sf::Vector2f oldScale, sf::Vector2f newScale, float interpolation)
{

        sf::Vector2f interPos = oldPosition + ((newPosition - oldPosition) * interpolation);
        float interAngle = InterpolateAngles(oldAngle,newAngle,interpolation);
        sf::Vector2f interScale = oldScale + ((newScale - oldScale) * interpolation);

        sf::Transform value;
        value.translate(interPos);
        value.scale(interScale);
        value.rotate(interAngle);
        return value;

}

float RenderMath::InterpolateAngles(float oldAngle,float newAngle, float interpolation)
{
     float difference = std::abs(newAngle - oldAngle);
        if (difference > 180)
        {
            if (newAngle > oldAngle)
            {
                oldAngle += 360;
            }
            else
            {
                newAngle += 360;
            }
        }

        // Interpolate it.
        float value = (oldAngle + ((newAngle - oldAngle) * interpolation));

        // Wrap it..
        float rangeZero = 360;

        if (value >= 0 && value <= 360)
           return value;
        else
        return (int)(value) % 360;

}

sf::ConvexShape RenderMath::CreateBoneShape(float length,float thickness)
{
	
	float radius = thickness / 2.f;
	
	sf::ConvexShape rect(39);
	//Start with top left rectangle point
	sf::Vector2f topLeft(0.f,-radius);
	sf::Vector2f bottomRight(length,radius);
	int currentPoint = 0;
	
	//rect.append(sf::Vertex(topLeft,color));

	//Add left circle half
	for (int angle = 90; angle <= 270; angle += 10)
	{
		float radAngle = evolve::Conversions::DegreesToRadians(angle);
		sf::Vector2f cPoint(cos(radAngle),sin(radAngle));
		cPoint *= radius;
		rect.setPoint(currentPoint,cPoint);
		currentPoint++;
	}

	//Add Right Circle half
	for (int angle = 270; angle <= 360; angle += 10)
	{
		float radAngle = evolve::Conversions::DegreesToRadians(angle);
		sf::Vector2f cPoint(cos(radAngle),sin(radAngle));
		cPoint *= radius;
		cPoint.x += length;
		rect.setPoint(currentPoint,cPoint);
		currentPoint++;
	}

	for (int angle = 0; angle <= 90; angle += 10)
	{
		float radAngle = evolve::Conversions::DegreesToRadians(angle);
		sf::Vector2f cPoint(cos(radAngle),sin(radAngle));
		cPoint *= radius;
		cPoint.x += length;
		rect.setPoint(currentPoint,cPoint);
		currentPoint++;
	}
	return rect;


}



