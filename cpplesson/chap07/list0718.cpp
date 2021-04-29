// integer object dynamic generate

#include <iostream>

using namespace std;

int main()
{
	int *x = new int;
	cout << "interger : " ;
	cin >> *x;
	cout << "*x = " << *x << '\n';
	delete x;
}

