#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>
#include <new>

class Weapon
{
    private:
    std::string type;

    public:
    Weapon();
    Weapon(std::string type);
    ~Weapon();

    void setType(std::string type);
    std::string getType() const;

};

#endif