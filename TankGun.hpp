#ifndef __TANKGUN_HPP__
#define __TANKGUN_HPP__

#include "Weapon.hpp"

class TankGun : public Weapon {
	protected:
		
	public:
		TankGun();
		~TankGun() {};

		std::string toString() const;
		friend std::ostream& operator<<(std::ostream & out, TankGun const & d);
};

#endif