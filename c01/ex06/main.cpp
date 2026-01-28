#include "harl.hpp"

int	Harl_converter(char *argv)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
		if (levels[i] == argv)
			return (i);
	return (-1);
}

void	Harl_switch(char *argv, Harl & H)
{
	switch (Harl_converter(argv))
	{
		case 0:
			H.complain("DEBUG");
		case 1:
			H.complain("INFO");
		case 2:
			H.complain("WARNING");
		case 3:
			H.complain("ERROR");
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

int	main(int argc, char **argv)
{
	Harl H;

	if (argc != 2)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	else
		Harl_switch(argv[1], H);
	return (0);
}