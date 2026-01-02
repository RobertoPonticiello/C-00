#include "Zombie.hpp"

int main(void)
{
	Zombie *newZombie1;
	int i = 10;
	int count = 0;
	
	newZombie1 = zombieHorde( i, "BRIAN");
	while (count < i)
	{
		newZombie1[count].announce();
		count++;
	}
	delete[] newZombie1;
	return (0);
}