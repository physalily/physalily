#include <iostream>
#include <cstdlib>
#include <time.h>
#include <random>

int main()
{
	// parameter for simulation.
	size_t simulation_iter;

	// result parameter.
	int slave_win = 0;
	int king_win = 0;
	
	// valiable for simulation.
	int slave_card = 0;
	int king_card = 0;

	// random setup
	// seed settings
	std::random_device seed_gen;
	std::default_random_engine engine(seed_gen());
	// generate random number 1 to 5
	std::uniform_int_distribution<> dist(1, 5);

	// main loop
	for (size_t i = 0; i < simulation_iter; i++) {
		slave_card = dist(engine);
		king_card = dist(engine);
		std::cout << slave_card << std::endl;
		std::cout << king_card << std::endl;
		if (slave_card == 1 && king_card == 5)
			slave_win++;
		else if(slave_card < king_card)
			king_win++;
		else 
			std::cout << "error... whoever won.";
	}

	// display result
	std::cout << "slave win: " << slave_win << std::endl;
	std::cout << " king win: " << king_win  << std::endl;
	if (slave_win == 0) {
		std::cout << "zero d error." << std::endl;
		return 0;
	}
	std::cout << " probability : " << (double)slave_win / (double)simulation_iter 
		<< std::endl;

	return 0;
}
