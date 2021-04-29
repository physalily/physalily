// integer object dynamic generate

#include <iostream>

using namespace std;

int main()
{
	int *x = new int(5);
	cout << "*x = " << *x << '\n';
	delete x;
}

