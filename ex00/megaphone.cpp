#include <iostream>

int main (int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}

	int i = 0;
	int j = 1;
	unsigned char c;

	while (j < argc)
	{
		while (argv[j][i])
		{
			c = std::toupper(argv[j][i]);
			std::cout << c;
			i++;
		}
		i = 0;
		j++;
	}
	std::cout << '\n';
	return (0);
}