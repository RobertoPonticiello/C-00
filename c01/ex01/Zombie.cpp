#include "Zombie.hpp"

void Zombie::announce( void )
{
    std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." <<  std::endl;
}

void Zombie::setname(std::string  name)
{
    this->name = name;
}

Zombie::Zombie()
{
}

Zombie::Zombie(std::string  name)
{
    this->name = name;
}

Zombie::~Zombie()
{
}