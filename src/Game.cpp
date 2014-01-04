#include "Game.h"
#include <memory>
#include <Organism/Hub.h>
#include <Organism/Organism.h>
Game::Game()
{
    //ctors
	oldMouse = sf::Mouse::getPosition();
	skinTexture = new sf::Texture();
	if (!skinTexture->loadFromFile("skin.jpg"))
	{
		int a =1;
	}
	skinTexture->setSmooth(true);
}

Game::~Game()
{
    //dtor
}

void Game::createWindow()
{

    gameWindow.create(sf::VideoMode(800, 800), "SFML window");
    gameWindow.setVerticalSyncEnabled(false);
	mainView.setCenter(sf::Vector2f(0.f,0.f));
	mainView.setSize(10.f,10.f);
	gameWindow.setView(mainView);
}

void Game::createWorld()
{
	SceneGraph = new SceneNode();

	Organism::Ptr mOrganism(new Organism());
	
	Bone::Ptr uArm(new Bone(6.f,0,180.f));
	Bone::Ptr lArm(new Bone(5.f,0,180.f));
	Hub::Ptr wrist(new Hub(.5f,-35.f,35.f));
	
	uArm->canControl = true;

	uArm->SetID(1);
	lArm->SetID(2);
	wrist->SetID(3);
	

	uArm->AttachSkin(.8f,skinTexture);
	lArm->AttachSkin(.5f,skinTexture);
	wrist->AttachSkin(.01,skinTexture);

	
	
	for (int i = 0; i < 5; i++)
	{
		float foo[5];
		foo[0] = -45;
		foo[1] = -22.5;
		foo[2] = 0;
		foo[3] = 22.5;
		foo[4] = 45;
		Bone::Ptr fA(new Bone(.6f,-40.f,40.f));
		Bone::Ptr fB(new Bone(.5f,-30.f,30.f));
		fA->AttachSkin(.1f,skinTexture);
		fB->AttachSkin(.1f,skinTexture);
		
		int ID = (i + 1) * 100;
		fA->SetID(ID);
		fB->SetID(ID + 1);


		fA->AttachSkeletalComponent(std::move(fB));
		wrist->AttachBone(std::move(fA),foo[i]);
	}




	lArm->AttachSkeletalComponent(std::move(wrist));
	uArm->AttachSkeletalComponent(std::move(lArm));

	uArm->SetOrganism(mOrganism.get());
	mOrganism->AttachSkeletalComponent(std::move(uArm));
	mOrganism->SetGame(this);
	SceneGraph->AttachChild(std::move(mOrganism));

}

sf::RenderWindow* Game::GetWindow()
{
	return &gameWindow;
}

evolve::Vec2 Game::GetMouseWorldPosition()
{
	
	sf::Vector2i pixelPos = sf::Mouse::getPosition(gameWindow);
	// convert it to world coordinates
	sf::Vector2f worldPos = gameWindow.mapPixelToCoords(pixelPos,mainView);
	return evolve::Vec2(worldPos);
}

void Game::mainLoop()
{
    while (gameWindow.isOpen())
    {
        //Game Loop
        mTimestep.startLoop();

        processEvents();

        while(mTimestep.canUpdate())
            update(mTimestep.TIMESTEP);

        render(mTimestep.getAlpha());

        //End Game Loop
    }
}

void Game::render(const float alpha)
{
    gameWindow.clear();
    sf::RenderStates states;
	gameWindow.setView(mainView);
    //newBone->Render(gameWindow,states,(*this),0.f);
    SceneGraph->Render(gameWindow,states,(*this),alpha);

	gameWindow.setView(gameWindow.getDefaultView());
	gameWindow.draw(debugInfo);
    debugInfo.updateFPS();
	gameWindow.display();

}

void Game::update(const float dt)
{
	
	int32 velocityIterations = 8;   //how strongly to correct velocity
    int32 positionIterations = 3;
	//world->Step( dt, velocityIterations, positionIterations);
	debugInfo.update(gameWindow);

	sf::Vector2i newMouse = sf::Mouse::getPosition(gameWindow);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					//Pan View

					sf::Vector2i difference = (oldMouse - newMouse);
					sf::Vector2f amount = sf::Vector2f(difference.x,difference.y);
					amount = amount * (mainView.getSize().x/400.f);


					mainView.move(amount.x,amount.y);

				}
				float movement = 1.0;

				float d = 0.f;


				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
					mainView.zoom(1.2f);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
					mainView.zoom(0.8f);
	oldMouse = newMouse;


	SceneGraph->Update(dt);
}



void Game::processEvents()
{
     sf::Event event;
        while (gameWindow.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
            {
                gameWindow.close();
            }
            if (event.type == sf::Event::EventType::KeyPressed)
            {

            }
			if (event.type == sf::Event::EventType::MouseWheelMoved)
			{
				int maxDelta = 5;
				int delta = event.mouseWheel.delta;
				float speed = 1.5;
				float movement = 0.0f;
				if (delta > 0)
					movement = 1/speed;
				if (delta < 0)
					movement = speed/1;
				mainView.zoom(movement);
			}


        }
}
