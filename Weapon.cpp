// core
#include "stdafx.hpp"

#include "Weapon.hpp"

std::vector<std::string> weaponVect{"Drone", "Hologlove", "TankGun", "Defibrillator"};

Weapon::Weapon() {}

Weapon::Weapon(std::string name) : _name(name) {}

Weapon::~Weapon() {}

std::string Weapon::toString() const {
	std::stringstream ss;
	ss << "\nWeapon's name: " << this->get_name() << "\nWeapon's power: " << this->get_power() << "\nWeapon's range: " << this->get_range() << std::endl ;
	return ss.str(); 
}

std::ostream& operator<<(std::ostream & out, Weapon const & w) {
	out << w.toString();
	return out;
}