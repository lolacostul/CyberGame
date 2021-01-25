#ifndef __GUNBREAKER_HPP__
#define __GUNBREAKER_HPP__

#include "Player.hpp"
#include "TankGun.hpp"

class Gunbreaker : public Player {
	protected:
		// std::string characterClass = "Gunbreaker";
	public:
		Gunbreaker(float x, float y, sf::Texture& texture);
		~Gunbreaker();

		std::string toString() const;
		friend std::ostream& operator<<(std::ostream & out, Gunbreaker const & gb);
};

#endif