#include <Bodypart.h>
#include <Box2D/Box2D.h>
#include <memory>
#define RADIANS_TO_DEGREES(__ANGLE__) ((__ANGLE__) / M_PI * 180.0)
Bodypart::Bodypart(void)
{
}


Bodypart::~Bodypart(void)
{
}

Bodypart::Ptr Bodypart::Create(Bodypart::BodypartProperties properties, b2World& world)
{
    Bodypart::Ptr bPart(new Bodypart());

    b2BodyDef newBodyDef;
    newBodyDef.position.Set(properties.x,properties.y);
    newBodyDef.angle = properties.angle;
    newBodyDef.type = b2_dynamicBody;
    b2Body * nBody = world.CreateBody(&newBodyDef);
    //Initialize Body


    b2FixtureDef newFixtureDef;
    newFixtureDef.density = properties.density;
    b2PolygonShape shape;
    b2Vec2 shapeCenter;
    shapeCenter.x =  properties.width/2.f;
    shapeCenter.y = properties.height/2.f;
    shape.SetAsBox(shapeCenter.x,shapeCenter.y);
    newFixtureDef.shape = &shape;
    newFixtureDef.restitution = 1.0f;
    nBody->CreateFixture(&newFixtureDef);
    if (properties.shape == 1)
    {
        b2Vec2 speed = b2Vec2(0.f,1.f);
        //nBody->SetLinearVelocity(speed);
        nBody->SetAngularVelocity(0.f);
    }
    else
    {
        nBody->SetAngularVelocity(-6.5f);
       // nBody->SetLinearVelocity(b2Vec2(-4.5f,-.5f));
    }
    bPart->mBody = nBody;


    std::unique_ptr<sf::RectangleShape> rect(new sf::RectangleShape(sf::Vector2f(properties.width,properties.height)));
    rect->setOrigin(shapeCenter.x,shapeCenter.y);
    rect->setRotation(properties.angle);
    rect->setFillColor(properties.color);
    bPart->visibleRepresentation = std::move(rect);
    return std::move(bPart);
}

void Bodypart::AttachBodypart(b2Body * bodypart, b2Vec2 &jointPos)
{
    b2RevoluteJointDef jDef;
    jDef.bodyA = bodypart;
    jDef.bodyB = mBody;
    jDef.collideConnected  = true;
    jDef.localAnchorA = jointPos;
   // jDef.localAnchorB = jointPos;
    mBody->GetWorld()->CreateJoint(&jDef);
}

void Bodypart::RenderSelf(sf::RenderTarget &target,Game &game,float interpolation)
{
    sf::RenderStates states;
    const b2Vec2 pos = mBody->GetPosition();
    states.transform.translate(pos.x,pos.y);


    float angle = RADIANS_TO_DEGREES(mBody->GetAngle());
while (angle <= 0){
   angle += 360;
}
while (angle > 360){
   angle -= 360;
}



    states.transform.rotate(angle);
    target.draw((*visibleRepresentation),states);
}
