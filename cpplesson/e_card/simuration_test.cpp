#include <iostream>
#include <cstdlib>
#include <time.h>

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

	// main loop
	for (size_t i = 0; i < simulation_iter; i++) {
		srand(time(NULL));
		slave_card = rand() % 5 + 1;
		srand(time(NULL));
		king_card = rand() % 5 + 1;
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
		std::cout << "zero d error.";
		return 0;
	}
	std::cout << " probability : " << (double)slave_win / (double)simulation_iter 
		<< std::endl;

	return 0;
}
