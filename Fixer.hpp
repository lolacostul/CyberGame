#ifndef __FIXER_HPP__
#define __FIXER_HPP__
#pragma once

#include "Player.hpp"
#include "Defibrillator.hpp"

class Fixer : public Player {
	protected:
	public:
		Fixer(float x, float y, sf::Texture& texture);
		~Fixer();
		std::string toString() const;
		friend std::ostream& operator<<(std::ostream & out, Fixer const & fx);
};

#endif