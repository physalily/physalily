// expeption 

#include <new>
#include <iostream>

using namespace std;

int main()
{
	cout << "create big array\n";

	while (true) {
		try {
			double* a = new double[300000];
		} catch (bad_alloc) {
			cout << "fail generate array. \n";
			return 1;
		}
	}
}

