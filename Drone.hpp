#ifndef __DRONE_HPP__
#define __DRONE_HPP__
#pragma once

#include "Weapon.hpp"

class Drone : public Weapon {
	protected:
		
	public:
		Drone();
		~Drone() {};

		std::string toString() const;
		friend std::ostream& operator<<(std::ostream & out, Drone const & d);
};

#endif