#include "../Util/Globalvar.h"
#include "../RescoureManager/ResourceHolder.h"
#include "StateManager.h"
#include "GameState.h"


GameState::GameState(sf::RenderWindow *p_rw, StateManager *p_sm)
	: BaseState	(p_rw, p_sm)
{
	pCamera = new Camera(p_rw);
	pCamera->setAsCurrent();
	pCamera->setZoom(0.3f);
	pCamera->setCenter(264.f, 132.f);
	pCamera->setMinMaxPos(0.f, 0.f, 528.f, 254.f);

	pMiniMap = new Minimap(rw, sf::Vector2f(.0f, 0.f), sf::Vector2f(528.f, 254.f));

	GUI_Manager = new gui::GUIManager(rw);

	GUI_Manager->pushWidget<gui::Button>("Beenden", gui::Small);
	GUI_Manager->setText("Beenden", "X");
	GUI_Manager->setPositon("Beenden", sf::Vector2f(800.0f - 128.0f, 0.0f));
	GUI_Manager->setFunction("Beenden", std::bind(&StateManager::Quit, pStateManager));

	const int level[] =
	{
		16, 16, 16, 16, 16, 16, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
		16, 114, 114, 114, 114, 114, 114, 16, 16, 16, 16, 107, 16, 16, 16, 16,
		114, 114, 16, 16, 16, 16, 16, 16, 3, 3, 3, 3, 3, 3, 3, 3,
		16, 114, 16, 16, 107, 16, 3, 3, 3, 16, 114, 114, 114, 16, 16, 16,
		16, 114, 114, 16, 3, 3, 3, 16, 16, 16, 114, 114, 114, 107, 16, 16,
		16, 16, 114, 16, 3, 16, 107, 107, 16, 16, 114, 114, 114, 114, 107, 16,
		107, 16, 114, 16, 3, 16, 107, 107, 107, 16, 114, 114, 114, 114, 114, 114,
		16, 16, 114, 16, 3, 107, 107, 107, 16, 16, 16, 16, 114, 114, 114, 114,
	};

	pMap = new TileMap;
	if (!pMap->load("tileset.png", sf::Vector2u(33, 33), level, 16, 8))
		std::cout << "Tilemap didn't load.\n";
	//pMap->setPosition(-264.f, -132.f);
	//pMap->scale(4.0f, 4.0f);

	//DS = new DialogSystem;
	//DS->getCurrentDialog("res/txt/Dialog/Rufus/Rufus_Intro_1.txt");

	//GUI_Manager->pushWidget<gui::Label>("Pos", "Pos: (0, 0)");
	//GUI_Manager->setPositon("Pos", sf::Vector2f(0.0f, 100.0f));

	//pTest = new sf::Sprite(*ResourceHolder::get().texture.get("test"));

	//PHY_Scene = new phy::PhysicScene(rw);
	//PHY_Scene->pushParticle<phy::Particle>("Test", pTest);
	//PHY_Scene->setPositon("Test", sf::Vector2f(400.0f, 150.0f));

	//PHY_Scene->addForceType<phy::weight_force>("Test", 100.0f);
	//PHY_Scene->addForceType<phy::spring_force>("Test", 2.0f);
}

GameState::~GameState()
{
	//delete PHY_Scene;
	//delete pTest;
	//delete DS;
	delete pMap;
	delete GUI_Manager;
	delete pMiniMap;
	delete pCamera;

	//PHY_Scene	= nullptr;
	//pTest		= nullptr;
	//DS			= nullptr;
	pMap		= nullptr;
	GUI_Manager	= nullptr;
	pMiniMap	= nullptr;
	pCamera		= nullptr;
}

void GameState::handleEvent(sf::Event e)
{
	pCamera->handelKeys(e);

	GUI_Manager->handleEvent(e);
}

void GameState::handleInput()
{
	GUI_Manager->handleInput();
}

void GameState::update(float frametime)
{
	GUI_Manager->update(frametime);
}

void GameState::fixedUpdate(float frametime)
{
	GUI_Manager->fixedUpdate(frametime);
	//PHY_Scene->fixedUpdate(frametime);

	//GUI_Manager->setText("Pos", "Pos: (" + std::to_string(PHY_Scene->getPosition("Test").x) + ", "
			//+ std::to_string(PHY_Scene->getPosition("Test").y) + ")");
}

void GameState::render()
{
	pCamera->setAsCurrent();

	//rw->draw(*pTest);
	rw->draw(*pMap);
	GUI_Manager->render();
	
	pMiniMap->setAsCurrent();
	rw->draw(*pMap);

	pCamera->setAsCurrent();
}

void GameState::setVolume(float f)
{
	GUI_Manager->setVolume(f);
}
