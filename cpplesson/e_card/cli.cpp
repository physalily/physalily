#include <iostream>
#include <random>

int main()
{
	std::cout << "Game start." << std::endl;
	while (true)
	{
		// setup
		int role = 0;
		std::cout << "Select your role. king:1 or slave:2" << std::endl;
		std::cin >> role;
		std::cout << "your select ";
		if ( role == 1 )  {
			std::cout << "king!" << std::endl;
		}
		else if (role == 2 ) {
			std::cout << "slave!" << std::endl;
		}
		else {
			std::cout << "ERROR";
			return 0;
		}
		// random setup
		// seed settings
		std::random_device seed_gen;
		std::default_random_engine engine(seed_gen());
		// 0 to 4 dist cause it use in array index.
		std::uniform_int_distribution<> nomally_dist(0, 4);

		// do game
		break;
	}
	return 0;
}

