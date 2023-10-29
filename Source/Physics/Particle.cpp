#include "Particle.h"

#include <iostream>

namespace phy
{
	Particle::Particle(sf::Sprite *particle)
	{
		Inertia = sf::Vector2f(0, 0);

		pParticle = particle;

		p = sf::Vector2f(0, 0);
		v = sf::Vector2f(0, 0);
		a = sf::Vector2f(0, 0);
		F = sf::Vector2f(0, 0);

		m = 1.0f;
	}

	Particle::~Particle()
	{
		pParticle = nullptr;
	}

	void Particle::pushForce(std::unique_ptr<phy::force> force)
	{
		mForces.push_back(std::move(force));
	}

	void Particle::fixedUpdate(float dt)
	{
		SumForces();

		p += (v * dt) + (a * (0.5f * dt*dt));
		sf::Vector2f new_a = (a + (F / m)) / 2.0f;
		v += new_a * dt;

		F = sf::Vector2f(0, 0);

		if (pParticle != nullptr)
			pParticle->setPosition(p);
	}

	void Particle::SumForces()
	{
		for (auto it = mForces.begin(); it != mForces.end(); it++)
		{
			addForce(it->get()->getForce());
		}
	}
}
