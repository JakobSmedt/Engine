#include "../Util/Globalvar.h"
#include "../RescoureManager/ResourceHolder.h"
#include "StateManager.h"
#include "MenuState.h"


MenuState::MenuState(sf::RenderWindow *p_rw, StateManager *p_sm)
	: BaseState		(p_rw, p_sm)
	, ShowSettings	(false)
{
	pTxrsAnim = new TextureAnimation(256, 256);
	pTxrsAnim->addUniform(3, sf::seconds(0.1f));

	pAnim = new sf::Sprite(*ResourceHolder::get().texture.get("Run"));
	pAnim->setPosition(sf::Vector2f(100, 100));
	pAnim->setScale(sf::Vector2f(0.4f, 0.4f));
	pAnim->setTextureRect(*pTxrsAnim->getFrame());


	GUI_Manager = new gui::GUIManager(rw);

	GUI_Manager->pushWidget<gui::Button>("Start", gui::Wide);
	GUI_Manager->setText("Start", "Start");
	GUI_Manager->setPositon("Start", sf::Vector2f(300.0f, 100.0f));
	GUI_Manager->setFunction("Start", std::bind(&MenuState::start, this));
	GUI_Manager->setTexture("Start", ResourceHolder::get().texture.get("Button"));
	GUI_Manager->setSoundBuffer("Start", ResourceHolder::get().soundbuffer.get("ButtonClick"));

	GUI_Manager->pushWidget<gui::Button>("Einstellungen", gui::Wide);
	GUI_Manager->setText("Einstellungen", "Einstellungen");
	GUI_Manager->setPositon("Einstellungen", sf::Vector2f(300.0f, 200.0f));
	GUI_Manager->setFunction("Einstellungen", std::bind(&MenuState::setting, this));
	GUI_Manager->setTexture("Einstellungen", ResourceHolder::get().texture.get("Button"));
	GUI_Manager->setSoundBuffer("Einstellungen", ResourceHolder::get().soundbuffer.get("ButtonClick"));

	GUI_Manager->pushWidget<gui::Button>("Beenden", gui::Small);
	GUI_Manager->setText("Beenden", "Beenden");
	GUI_Manager->setPositon("Beenden", sf::Vector2f(300.0f, 400.0f));
	GUI_Manager->setFunction("Beenden", std::bind(&StateManager::Quit, pStateManager));

	/*GUI_Manager->pushWidget<gui::Button>("Send", gui::Small);
	GUI_Manager->setText("Send", "Send");
	GUI_Manager->setPositon("Send", sf::Vector2f(300.0f, 500.0f));
	GUI_Manager->setFunction("Send", std::bind(&MenuState::send, this));*/

	GUI_Manager->pushWidget<gui::TextBox>("Textbox", "Initial Text.");
	GUI_Manager->setPositon("Textbox", sf::Vector2f(300.0f, 300.0f));


	GUI_Manager->pushWidget<gui::Checkbox>("Checkbox", true);
	GUI_Manager->setPositon("Checkbox", sf::Vector2f(100.0f, 300.0f));

	GUI_Manager->pushWidget<gui::LoadingBar>("LoadingBar", 0.24f);
	GUI_Manager->setPositon("LoadingBar", sf::Vector2f(10.0f, 550.0f));


	GUI_Einstellungen = new gui::GUIManager(rw);
	GUI_Einstellungen->pushWidget<gui::Button>("Zurück", gui::Small);
	GUI_Einstellungen->setText("Zurück", "Zurück");
	GUI_Einstellungen->setPositon("Zurück", sf::Vector2f(100.0f, 500.0f));
	GUI_Einstellungen->setFunction("Zurück", std::bind(&MenuState::ToogelMenu, this));

	GUI_Einstellungen->pushWidget<gui::Button>("Anwenden", gui::Small);
	GUI_Einstellungen->setText("Anwenden", "Anwenden");
	GUI_Einstellungen->setPositon("Anwenden", sf::Vector2f(500.0f, 600.0f));
	GUI_Einstellungen->setFunction("Anwenden", std::bind(&MenuState::Apply, this));
	GUI_Einstellungen->setSoundBuffer("Anwenden", ResourceHolder::get().soundbuffer.get("ButtonClick"));

	GUI_Einstellungen->pushWidget<gui::Slider>("Slider", 1.0f);
	GUI_Einstellungen->setPositon("Slider", sf::Vector2f(300.0f, 300.0f));
	GUI_Einstellungen->setFloat("Slider", 0.01f);

	GUI_Einstellungen->pushWidget<gui::Label>("Volume_Label", "Volume");
	GUI_Einstellungen->setPositon("Volume_Label", sf::Vector2f(300.0f, 270.0f));


	//mSocket.connect("192.168.2.119", 65432);
	//mSocket.setBlocking(false);

	//std::cout << mSocket.getRemoteAddress() << std::endl;
}

MenuState::~MenuState()
{
	//mSocket.disconnect();

	delete GUI_Einstellungen;
	delete GUI_Manager;
	delete pAnim;
	delete pTxrsAnim;

	GUI_Einstellungen = nullptr;
	GUI_Manager	      = nullptr;
	pAnim		      = nullptr;
	pTxrsAnim	      = nullptr;
}

void MenuState::handleEvent(sf::Event e)
{
	if(ShowSettings)
		GUI_Einstellungen->handleEvent(e);
	else
		GUI_Manager->handleEvent(e);
}

void MenuState::handleInput()
{
	if (ShowSettings)
		GUI_Einstellungen->handleInput();
	else
		GUI_Manager->handleInput();
}

void MenuState::update(float frametime)
{
	if (ShowSettings)
		GUI_Einstellungen->update(frametime);
	else
	{
		GUI_Manager->update(frametime);

		pAnim->setTextureRect(*pTxrsAnim->getFrame());


		/*sf::Packet packet;
		std::string s;
		mSocket.receive(packet);

		if (packet >> s)
		{
			std::cout << "Recived: " << s << std::endl;
		}*/
	}
}

void MenuState::fixedUpdate(float frametime)
{
	if (ShowSettings)
		GUI_Einstellungen->fixedUpdate(frametime);
	else
		GUI_Manager->fixedUpdate(frametime);
}

void MenuState::render()
{
	if (ShowSettings)
		GUI_Einstellungen->render();
	else
	{
		GUI_Manager->render();

		rw->draw(*pAnim);
	}
}

void MenuState::setVolume(float f)
{
	//std::cout << "Volume now: " << f << std::endl;
	GUI_Manager->setVolume(f);
	GUI_Einstellungen->setVolume(f);

}

void MenuState::start()
{
	pStateManager->pushState<GameState>("Game_0", rw, pStateManager);
	pStateManager->nextState("Game_0");
	pStateManager->deleteState("Menu_0");
}

void MenuState::setting()
{
	std::cout << std::boolalpha;
	std::cout << "Checkbox is: " << GUI_Manager->getBool("Checkbox") << ". And Textbox is: " << GUI_Manager->getText("Textbox")
		<<  std::endl;
	ToogelMenu();
}

void MenuState::ToogelMenu()
{
	ShowSettings = !ShowSettings;
}

void MenuState::Apply()
{
	pStateManager->setVolume(GUI_Einstellungen->getFloat("Slider") * 100.0f);
}

void MenuState::send()
{
	std::string message = GUI_Manager->getText("Textbox");
	size_t t = message.length();
	sf::Packet packet;
	std::string s;

	//QuickSend("192.168.2.119", message, 65431);
	std::cout << "Sending: " << message << std::endl;
	mSocket.send(message.c_str(), t);

	mSocket.receive(packet);

	//packet >> s;

	//std::cout << "Recived: " << packet.getData() << std::endl;
}


