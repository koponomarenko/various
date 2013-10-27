#include <iostream>
#include "Cpmv.h"

Cpmv::Cpmv() : pi(nullptr)
{
	std::cout << "Cpmv::Cpmv()" << std::endl; // just display info
}

Cpmv::Cpmv(std::string q, std::string z)
{
	std::cout << "Cpmv::Cpmv(std::string q, std::string z)" << std::endl; // just display info
	pi = new Info {q, z};
}

Cpmv::Cpmv(const Cpmv & cp)
{
	std::cout << "Cpmv::Cpmv(const Cpmv & cp)" << std::endl; // just display info
	pi = new Info {cp.pi->qcode, cp.pi->zcode};
}

Cpmv::Cpmv(Cpmv && mv)
{
	std::cout << "Cpmv::Cpmv(Cpmv && mv)" << std::endl; // just display info
	pi = mv.pi;
	mv.pi = nullptr;
}

Cpmv::~Cpmv()
{
	std::cout << "Cpmv::~Cpmv()" << std::endl; // just display info
	delete pi;
}


Cpmv & Cpmv::operator=(const Cpmv & cp)
{
	std::cout << "Cpmv::operator=(const Cpmv & cp)" << std::endl; // just display info
	if (this == &cp)
		return *this;
	
	delete pi;
	pi = new Info {cp.pi->qcode, cp.pi->zcode};
	return *this;
}

Cpmv & Cpmv::operator=(Cpmv && mv)
{
	std::cout << "Cpmv::operator=(Cpmv && mv)" << std::endl; // just display info
	delete pi;
	pi = mv.pi;
	mv.pi = nullptr;
	return *this;
}

Cpmv Cpmv::operator+(const Cpmv & obj) const
{
	std::cout << "Cpmv::operator+(const Cpmv & obj) const" << std::endl; // just display info
	return Cpmv(pi->qcode + obj.pi->qcode, pi->zcode + obj.pi->zcode);
}

void Cpmv::Display() const
{
	std::cout << "Cpmv::Display() const" << std::endl; // just display info
	std::cout << "qcode: " << pi->qcode << std::endl;
	std::cout << "zcode: " << pi->zcode << std::endl;
}
