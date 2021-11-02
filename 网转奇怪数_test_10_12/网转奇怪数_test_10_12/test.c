#include <stdio.h>
#include <math.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_NUM 1000
int strangeNumber(int);// �ж��Ƿ��������
int sum;// ���ӵĺ�
int factor[MAX_NUM];// ��������
int factorNum;// ���Ӹ���
int abundantNumber(int);// �ж��Ƿ���ӯ��
int back(int, int);// �����ж��Ƿ����Ӽ��ĺ���num

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
		return FALSE;// ����ӯ���������������
	}
	if (FALSE == back(0, num)) {
		return FALSE;// �����Ӽ��ĺ�Ϊnum�������������
	}
	return TRUE;
}
//���ȱ�����ӯ��
int abundantNumber(int num) {
	// ��ʼ��
	memset(factor, 0, sizeof(factor));
	factorNum = 0;
	factor[factorNum++] = 1;// 1�϶�������
	sum = 1;
	int max = (int)sqrt(num);
	// ѭ���ҵ�num����������
	for (int i = 2; i <= max; ++i) {
		if (0 == num % i) {
			factor[factorNum++] = i;
			factor[factorNum++] = num / i;
			sum += i + num / i;
		}
	}
	// num�ǿ���������ôѭ������max�������飬Ҫ���������
	if (max * max == num) {
		--factorNum;
		sum -= max;
	}
	return sum <= num ? FALSE : TRUE;
}
//�������������������ӵļ��ϣ�û���κ�һ���Ӽ����������ĺ͵������������
int back(int index, int left) {
	if (index >= factorNum) {
		return 0 == left ? FALSE : TRUE;
	}
	if (FALSE == back(index + 1, left)) {// ��ѡ���index����,����ݹ� 
		return FALSE;
	}
	//ѡ���index������ʣ��ļ�ȥ��ǰ��
	if (FALSE == back(index + 1, left - factor[index])) {
		return FALSE;
	}
	return TRUE;
}
