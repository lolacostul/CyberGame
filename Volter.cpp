// core
#include "stdafx.hpp"

#include "Volter.hpp"


Volter::Volter(float x, float y, sf::Texture& texture) : Player (x, y, texture) {
	std::cout << "Volter's default constructor\n";
	this->set_characterClass("Volter");
	this->set_hp(70);
	this->set_mana(35);
	this->_weapon = new Hologlove();
}

Volter::~Volter() {
	delete _weapon;
}


std::string Volter::toString() const {
	std::stringstream ss;
	ss << "Class: " << this->_characterClass << this->_weapon->toString() << Player::toString();
	return ss.str(); 
}

std::ostream& operator<<(std::ostream & out, Volter const & vt) {
	out << vt.toString();
	return out;
}