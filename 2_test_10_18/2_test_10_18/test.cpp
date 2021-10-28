#include <iostream>

using namespace std;

int gcd_int(int a, int b);

int main()
{
	int a = 16;
	int b = 8;

	cout << gcd_int(b, a) << endl;;

	return 0;
}

int gcd_int(int a, int b)
{
	int max = a;
	int min = b;

	if (a < b)
	{
		max = b;
		min = a;
	}

	int c = max - min;

	while (c)
	{
		max = min;
		min = c;
		c = max - min;
	}

	return min;
}