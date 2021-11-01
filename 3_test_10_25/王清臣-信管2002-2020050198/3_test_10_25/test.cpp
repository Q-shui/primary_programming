/*
*
*	�����ӣ�����������a,b��b % a == 0 �� a < b,�� a �� b �������ӡ�
*	����������һ����������������������ͣ����������������������������������
*			�� 6 �������Ӽ���{ 1, 2, 3 }��1 + 2 + 3 == 6���� 6 ����������
*	ӯ������һ����������������������ͣ���������������������ӯ����
*			�� 12 �������Ӽ���{ 1, 2, 3, 4, 6 },1 + 2 + 3 + 4 + 6 == 16 > 12,�� 12 ��ӯ����
*	��������һ����������������������ͣ����С��������������ǿ�����
*			�� 8 �������Ӽ���{ 1, 2, 4 }, 1 + 2 + 4 == 7 < 8,�� 8 �ǿ�����
*	�����������һ��ӯ���������Ӽ��ϣ��Ҳ����κ�һ���Ӽ���ʹ֮������������������ͺ������������������������
*			��ӯ�� 12 �������Ӽ���{ 1, 2, 3, 4, 6 }���Ӽ�{ 2, 4, 6 }���Ϊ12�� �� 12 �����������
*			ӯ�� 18 �������Ӽ���{ 1, 2, 3, 6, 9 }���Ӽ�{ 3, 6, 9 }���Ϊ18���� 18 �����������
*			ӯ�� 70 �������Ӽ���{ 1, 2, 5, 7, 10, 14, 35 }�Ҳ����κ�һ���Ӽ�ʹ�����Ϊ70���� 70 �������.
*
*
*	��1000���ڵ������
*
*/

//˼·������ĳ����a�������Ӽ���Ϊ{ a0, a1, a2, a3, a4, ... }
//			��a������������򼯺��е�ĳ������֮��Ϊa
//			��a - a0 �Ǽ���{ a1, a2, a3, a4 ... }��ĳ�������ĺͣ��⼸�����к���a0)
//			��a �Ǽ���{ a1, a2, a3, a4 ... }��ĳ�������ĺͣ��⼸��������a0)
//			�Դ˷�����ȥ
//
//
//



#include <iostream>
#include <vector>

using namespace std;

bool IsWeirdNumber(int n, vector<int>& a);//�ж��Ƿ��������
int SumVector(vector<int>& a);//�����Ӻ�

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

		int sum = SumVector(a);//�ж��Ƿ���ӯ��

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
	vector<int> b = a;//���´���һ��vector ��ֹ�ݹ������a���ı�

	if (n < 0)//n<0���� n ��ȥ�˲����Ӽ��е������˴εݹ���Ч
		return true;

	if (a.size() == 0 && n != 0)//n û�б���������������˴εݹ��ټ���ĳ�������е�һ���򼸸�
		return true;

	vector<int>::iterator result = find(b.begin(), b.end(), n);

	if (result != b.end())//�ӵ�ǰ��������ĳ��ֵ�Ƿ�Ϊn������У�����n�ܹ���ĳ���������꣬��n���������������false
		return false;
	else
	{
		int i = b.back();
		b.pop_back();

		return (IsWeirdNumber(n - i, b) && IsWeirdNumber(n, b));// && ȷ��ֻҪ��һ��false�򷵻�ֵΪ�٣��������������
	}


}

int SumVector(vector<int>& a)//�������ӵĺ�
{
	int sum = 0;

	for (auto i = 0; i < a.size(); i++)
	{
		sum += a[i];
	}

	return sum;
}