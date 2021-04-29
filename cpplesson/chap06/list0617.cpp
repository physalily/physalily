// check scope

#include <iostream>

using namespace std;

int x = 75;

void print_x()
{
	cout << "x = " << x << '\n';
}

int main()
{
	cout << "x = " << x << '\n';
	int x = 999;
	cout << "x = " << x << '\n';
	for (int i = 1; i <= 5; i++) {
		int x = i * 11;
		cout << "x = " << x << '\n';
	}

	cout << "x = " << x << '\n';
	cout << "::x = " << ::x << '\n';
	print_x();
}

