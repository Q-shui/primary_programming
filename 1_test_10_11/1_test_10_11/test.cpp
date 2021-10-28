#include <iostream>
#include <random>
#include <ctime>
#include <vector>

using namespace std;

int MaxCommonDivisor(int n, int m);

int main()
{
	int n, m;
	cin >> n >> m;

	cout << MaxCommonDivisor(n, m) << endl;
}

int MaxCommonDivisor(int n, int m)
{
	int l = n;
	int s = m;
	if (n < m)
	{
		l = m;
		s = n;
	}

	if (l % s != 0)
		MaxCommonDivisor(s, l % s);
	else
		return s;
}

//void Bubblesort(vector<int>& a, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n - i - 1; j++)
//		{
//			int tmp = 0;
//			if (a[j] < a[j + 1])
//			{
//				tmp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = tmp;
//			}
//		}
//	}
//
//}
//
//int main()
//{
//	srand((unsigned)time(0));
//
//
//	int N;
//	cin >> N;
//
//	vector<int> a;
//
//	for (int i = 0; i < N; i++)
//		a.push_back(rand() % 100);
//
//	for (int i = 0; i < N; i++)
//		cout << a[i] << endl;
//
//	Bubblesort(a, N);
//
//	cout << endl;
//
//	for (int i = 0; i < N; i++)
//		cout << a[i] << endl;
//
//	return 0;
//}

//int main()
//{
//	int a[10];
//	srand(time(NULL));
//	for (int i = 0; i <= 9; i++)
//	{
//		a[i] = rand() % 100;
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 10 - i - 1; j++)
//		{
//			int tmp = 0;
//			if (a[j] > a[j + 1])
//			{
//				tmp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = tmp;
//			}
//		}
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		std::cout << a[i] << " ";
//	}
//
//}


//int main()
//{
//	int a[10];
//	srand(time(NULL));
//	for (int i = 0; i <= 9; i++)
//	{
//		a[i] = rand() % 100;
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 10 - i -1; j++)
//		{
//			int tmp = 0;
//			if (a[j] > a[j + 1])
//			{
//				tmp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = tmp;
//			}
//		}
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		std::cout << a[i] << " ";
//	}
//
//}

//int main()
//{
//	std::cout << "hello world" << std::endl;
//
//	return 0;
//}