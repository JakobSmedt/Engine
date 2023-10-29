#pragma once

#include <SFML/Graphics.hpp>

#include "../Util/NonCopyable.h"



namespace phy
{
	class Particle;

	struct force : NonCopyable
	{
	public:
		force(Particle *particle)
			: pParticle(particle)
		{ }

		virtual sf::Vector2f getForce() { return sf::Vector2f(0.0f, 0.0f); };
	protected:
		Particle *pParticle;

	};


	struct weight_force : public force
	{
	public:
		weight_force(Particle *particle, float s = 100.0f, sf::Vector2f dir = sf::Vector2f(0.0f, 9.81f))
			: force		(particle)
			, scale		(s)
			, direction	(dir)
		{ }

		virtual sf::Vector2f getForce() override;
	private:
		sf::Vector2f direction;
		float scale;
	};


	struct spring_force : force
	{
	public:
		spring_force(Particle *particle, float k = 5.0f, sf::Vector2f anker = sf::Vector2f(400.0f, 300.0f))
			: force	(particle)
			, K		(k)
			, Anker	(anker)
		{ }

		virtual sf::Vector2f getForce() override;
	private:
		sf::Vector2f Anker;
		float K;
	};

}

