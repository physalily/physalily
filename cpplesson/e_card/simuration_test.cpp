#include <iostream>
#include <cstdlib>
#include <time.h>
#include <random>
#include <vector>

int main()
{
	// parameter for simulation.
	int simulation_iter = 100;

	// result parameter.
	int slave_win = 0;
	int king_win = 0;

	// random setup
	// seed settings
	std::random_device seed_gen;
	std::default_random_engine engine(seed_gen());
	// 0 to 4 dist cause it use in array index.
	std::uniform_int_distribution<> nomally_dist(0, 4);
	
	// input simulation loop times
	std::cout << "input simulation loop times in int: ";
	std::cin >> simulation_iter;
	
	// valiable for simulation.
	std::vector<std::vector<int>> slave_card_set(5, std::vector<int>(simulation_iter, 2));
	std::vector<std::vector<int>> king_card_set(5, std::vector<int>(simulation_iter, 2));

	// main loop
	for (size_t i = 0; i < simulation_iter; i++) {
		slave_card_set[nomally_dist(engine)][i] = 1;
		king_card_set[nomally_dist(engine)][i] = 3;
		for (size_t take = 0; take < 5; take++) {
			if (slave_card_set[take][i] == 1 && king_card_set[take][i] == 3) {
				slave_win++;
				break;
			}
			else if (slave_card_set[take][i] < king_card_set[take][i]) {
				king_win++;
				break;
			}
			else if (slave_card_set[take][i] == king_card_set[take][i]) {
				// draw
			}
		}
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
