#include <stdio.h>
#include <math.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_NUM 1000
int strangeNumber(int);// 判断是否是奇怪数
int sum;// 因子的和
int factor[MAX_NUM];// 保存因子
int factorNum;// 因子个数
int abundantNumber(int);// 判断是否是盈数
int back(int, int);// 回溯判断是否有子集的和是num

int main(void) {
	for (int i = 71; i <= 1000; ++i) {
		if (TRUE == strangeNumber(i)) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}

int strangeNumber(int num) {
	if (FALSE == abundantNumber(num)) {
		return FALSE;// 不是盈数，即不是奇怪数
	}
	if (FALSE == back(0, num)) {
		return FALSE;// 存在子集的和为num，即不是奇怪数
	}
	return TRUE;
}
//首先必须是盈数
int abundantNumber(int num) {
	// 初始化
	memset(factor, 0, sizeof(factor));
	factorNum = 0;
	factor[factorNum++] = 1;// 1肯定是因子
	sum = 1;
	int max = (int)sqrt(num);
	// 循环找到num的所有因子
	for (int i = 2; i <= max; ++i) {
		if (0 == num % i) {
			factor[factorNum++] = i;
			factor[factorNum++] = num / i;
			sum += i + num / i;
		}
	}
	// num是开方数，那么循环里面max加了两遍，要减掉多余的
	if (max * max == num) {
		--factorNum;
		sum -= max;
	}
	return sum <= num ? FALSE : TRUE;
}
//除了自身以外所有因子的集合，没有任何一个子集中所有数的和等于这个数本身
int back(int index, int left) {
	if (index >= factorNum) {
		return 0 == left ? FALSE : TRUE;
	}
	if (FALSE == back(index + 1, left)) {// 不选择第index个数,往后递归 
		return FALSE;
	}
	//选择第index个数，剩余的减去当前数
	if (FALSE == back(index + 1, left - factor[index])) {
		return FALSE;
	}
	return TRUE;
}
