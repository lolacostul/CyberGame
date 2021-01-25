#ifndef __VOLTER_HPP__
#define __VOLTER_HPP__

#include "Player.hpp"
#include "Hologlove.hpp"

class Volter : public Player {
	protected:
		// std::string _characterClass = "Volter";
	public:
		Volter(float x, float y, sf::Texture& texture);
		~Volter();

		std::string toString() const;
		friend std::ostream& operator<<(std::ostream & out, Volter const & vt);
};

#endif