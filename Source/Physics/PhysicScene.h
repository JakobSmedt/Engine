#pragma once

#include <unordered_map>
#include <string>

#include <SFML/Graphics.hpp>

#include "Particle.h"

namespace phy
{
	class PhysicScene
	{
	public:
		PhysicScene(sf::RenderWindow *p_rw);
		~PhysicScene();

		template<typename T, typename... Args>
		void pushParticle(std::string name, Args&&... args);
		void pushParticle(std::string name, std::unique_ptr<phy::Particle> particle);


		void fixedUpdate(float frametime);

		template<typename T, typename... Args>
		void addForceType(std::string name, Args&&... args);
		void addForce(std::string name, sf::Vector2f force) { mElements.at(name)->addForce(force); }

		void setPositon(std::string name, sf::Vector2f pos) { mElements.at(name)->setPosition(pos); };

		sf::Vector2f getPosition(std::string name) { return mElements.at(name)->getPosition(); };

	private:
		std::unordered_map<std::string, std::unique_ptr<phy::Particle>> mElements;

		sf::RenderWindow *rw;
	};

	template<typename T, typename... Args>
	inline void PhysicScene::pushParticle(std::string name, Args&&... args)
	{
		pushParticle(name, std::make_unique<T>(std::forward<Args>(args)...));
	};

	template<typename T, typename... Args>
	inline void PhysicScene::addForceType(std::string name, Args&&... args)
	{
		mElements.at(name)->pushForce<T>(std::forward<Args>(args)...);
	}
}

