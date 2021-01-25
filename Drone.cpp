// core
#include "stdafx.hpp"

#include "Drone.hpp"

Drone::Drone() {
	this->set_name("Drone");
	this->set_range(5);
	this->set_power(15);
}

std::string Drone::toString() const {
	std::stringstream ss;
	ss << Weapon::toString();
	return ss.str(); 
}

std::ostream& operator<<(std::ostream & out, Drone const & d) {
	out << d.toString();
	return out;
}