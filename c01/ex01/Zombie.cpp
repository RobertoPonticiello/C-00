#include "Zombie.hpp"

void Zombie::announce( void )
{
    std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." <<  std::endl;
}

void Zombie::setname(std::string  name)
{
    this->name = name;
}

Zombie::Zombie(std::string  name)
{
    this->name = name;
    std::cout << "Zombie named " << name << " is created." <<  std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie named " << name << " is dead." <<  std::endl;
}