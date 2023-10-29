#include "PhysicScene.h"

namespace phy
{
	PhysicScene::PhysicScene(sf::RenderWindow *p_rw)
	{

	}

	PhysicScene::~PhysicScene()
	{

	}

	void PhysicScene::pushParticle(std::string name, std::unique_ptr<phy::Particle> particle)
	{
		mElements.insert({ name, std::move(particle) });
	}

	void PhysicScene::fixedUpdate(float frametime)
	{
		for (auto it = mElements.begin(); it != mElements.end(); ++it)
		{
			it->second->fixedUpdate(frametime);
		}
	}
}