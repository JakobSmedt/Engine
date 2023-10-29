#include "Particle.h"
#include "Forces.h"

#include <iostream>

namespace phy
{
	sf::Vector2f weight_force::getForce() { return scale * direction; };

	sf::Vector2f spring_force::getForce() { return K * (Anker - pParticle->getPosition()); }

}