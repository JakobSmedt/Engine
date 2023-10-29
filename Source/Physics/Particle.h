#pragma once

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../Util/NonCopyable.h"
#include "Forces.h"

namespace phy
{
	class Particle : NonCopyable
	{
	public:
		 Particle(sf::Sprite *particle);
		~Particle();

		template<typename T, typename... Args>
		void pushForce(Args&&... args);
		void pushForce(std::unique_ptr<phy::force> force);

		void addForce(sf::Vector2f force) { F += force; }

		void fixedUpdate(float dt);

		void setPosition(sf::Vector2f pos)		{ p = pos; }
		void setVelocity(sf::Vector2f vel)		{ v = vel; }
		void setAcceleration(sf::Vector2f acc)	{ a = acc; }
		void setForce(sf::Vector2f force)		{ F = force; }
		void resetForce()						{ F.x = 0; F.y = 0; }
		void setMass(float M)					{ m = (M != 0.0f) ? M : 1.0f; }
		void setFriction(bool b)				{ friction = b; };

		sf::Vector2f getPosition()	{ return p; }
		float getRotation()			{ return theta; }
	private:
		void SumForces();

		std::vector<std::unique_ptr<phy::force>> mForces;

		sf::Sprite *pParticle;

		sf::Vector2f Inertia;
		sf::Vector2f p, v, a;
		sf::Vector2f F;

		float m, theta;

		bool friction = false;
	};

	template<typename T, typename... Args>
	inline void Particle::pushForce(Args&&... args)
	{
		pushForce(std::make_unique<T>(this, std::forward<Args>(args)...));
	};
}
