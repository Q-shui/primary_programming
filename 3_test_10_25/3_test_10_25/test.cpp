/*
*
*	真因子：对于两个数a,b若b % a == 0 且 a < b,则 a 是 b 的真因子。
*	完美数：对一个正整数的所有真因子求和，结果等于这个数自身，则这个数是完美数。
*			如 6 的真因子集是{ 1, 2, 3 }，1 + 2 + 3 == 6，则 6 是完美数。
*	盈数：对一个正整数的所有真因子求和，结果大于自身，则这个数是盈数。
*			如 12 的真因子集是{ 1, 2, 3, 4, 6 },1 + 2 + 3 + 4 + 6 == 16 > 12,故 12 是盈数。
*	亏数：对一个正整数的所有真因子求和，结果小于自身，则这个数是亏数。
*			如 8 的真因子集是{ 1, 2, 4 }, 1 + 2 + 4 == 7 < 8,故 8 是亏数。
*	奇怪数：对于一个盈数的真因子集合，找不到任何一个子集，使之对其中所有真因子求和后等于自身，则这个数是奇怪数。
*			如盈数 12 ，真因子集合{ 1, 2, 3, 4, 6 }的子集{ 2, 4, 6 }求和为12， 故 12 不是奇怪数；
*			盈数 18 ，真因子集合{ 1, 2, 3, 6, 9 }的子集{ 3, 6, 9 }求和为18，故 18 不是奇怪数；
*			盈数 70 ，真因子集合{ 1, 2, 5, 7, 10, 14, 35 }找不到任何一个子集使得其和为70，故 70 是奇怪数.
*
*
*	求1000以内的奇怪数
*
*/

//思路描述：某个数a的真因子集合为{ a0, a1, a2, a3, a4, ... }
//			若a不是奇怪数，则集合中的某几个数之和为a
//			即a - a0 是集合{ a1, a2, a3, a4 ... }中某几个数的和（这几个数中含有a0)
//			或a 是集合{ a1, a2, a3, a4 ... }中某几个数的和（这几个数不含a0)
//			以此分治下去
//
//
//



#include <iostream>
#include <vector>

using namespace std;

bool IsWeirdNumber(int n, vector<int>& a);//判断是否是奇怪数
int SumVector(vector<int>& a);//求因子和

int main()
{
	cout << "Please enter the range of number:[min, max]" << endl;

	int min, max;

	cin >> min >> max;

	for (int i = min; i <= max; i++)
	{


		vector<int> a;

		for (int j = 1; j < i; j++)
		{
			if (i % j == 0)
				a.push_back(j);
		}

		int sum = SumVector(a);//判断是否是盈数

		if (sum < i)
			cout << i << " is deficient number." << endl;

		if (sum == i)
			cout << i << " is Perfect number." << endl;

		if (sum > i && !IsWeirdNumber(i, a))
			cout << i << "is abundant number, not a werid number." << endl;

		if (sum > i && IsWeirdNumber(i, a))
			cout << i << " is weird number." << endl;
	}

	system("pause");

	return 0;
}

bool IsWeirdNumber(int n, vector<int>& a)
{
	vector<int> b = a;//重新创建一个vector 防止递归过程中a被改变

	if (n < 0)//n<0代表 n 减去了不在子集中的数，此次递归无效
		return true;

	if (a.size() == 0 && n != 0)//n 没有被减完的情况，代表此次递归少减了某几个数中的一个或几个
		return true;

	vector<int>::iterator result = find(b.begin(), b.end(), n);

	if (result != b.end())//从当前容器中找某个值是否为n，如果有，代表n能够被某几个数减完，则n不是奇怪数，返回false
		return false;
	else
	{
		int i = b.back();
		b.pop_back();

		return (IsWeirdNumber(n - i, b) && IsWeirdNumber(n, b));// && 确保只要有一个false则返回值为假，即不是奇怪数。
	}


}

int SumVector(vector<int>& a)//求真因子的和
{
	int sum = 0;

	for (auto i = 0; i < a.size(); i++)
	{
		sum += a[i];
	}

	return sum;
}