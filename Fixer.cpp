// core
#include "stdafx.hpp"

#include "Fixer.hpp"

Fixer::Fixer(float x, float y, sf::Texture& texture) : Player (x, y, texture) {
	std::cout << "Fixer's default constructor\n";
	this->set_characterClass("Fixer");
	this->set_hp(50);
	this->set_mana(80);
	this->_weapon = new Defibrillator();
}

Fixer::~Fixer() {
	delete _weapon;
}


std::string Fixer::toString() const {
	std::stringstream ss;
	ss << "Class: " << this->_characterClass << this->_weapon->toString() << Player::toString();
	return ss.str(); 
}

std::ostream& operator<<(std::ostream & out, Fixer const & fx) {
	out << fx.toString();
	return out;
}