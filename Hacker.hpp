#ifndef __HACKER_HPP__
#define __HACKER_HPP__

#include "Player.hpp"
#include "Drone.hpp"

class Hacker : public Player {
	protected:
	public:
		Hacker(float x, float y, sf::Texture& texture);
		~Hacker();
		std::string toString() const;
		friend std::ostream& operator<<(std::ostream & out, Hacker const & hk);
};

#endif