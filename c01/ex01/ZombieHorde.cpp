#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    int i = 0;
    Zombie *nZombie;
    nZombie = new Zombie[N];
    while (i < N)
    {
        nZombie[i].setname(name);
        i++;
    }
    return (nZombie);
}