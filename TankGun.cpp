// core
#include "stdafx.hpp"

#include "TankGun.hpp"

TankGun::TankGun() {
	this->set_name("TankGun");
	this->set_range(12);
	this->set_power(20);
}

std::string TankGun::toString() const {
	std::stringstream ss;
	ss << Weapon::toString();
	return ss.str(); 
}

std::ostream& operator<<(std::ostream & out, TankGun const & d) {
	out << d.toString();
	return out;
}