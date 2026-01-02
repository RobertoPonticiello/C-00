#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <new>

class Zombie
{
    private:
    std::string name;
    

    public:
    Zombie(std::string name);
    ~Zombie();

    void announce( void );
    void announce( std::string name );
    void setname(std::string  name);
};

Zombie* zombieHorde( int N, std::string name );


#endif