// 整数划分问题

#include<stdio.h>

int equationCount(int n, int m);

int main()
{
	int number;
	scanf("%d", &number);
	printf("%d\n", equationCount(number, number));
	return 0;
}

int equationCount(int n, int m)
{
	if (m == 1 || n == 1)
		return 1;
	else if (n < m)
		return equationCount(n, n);
	else if (n == m)
		return 1 + equationCount(n, m - 1);
	else
		return equationCount(n - m, m) + equationCount(n, m - 1);
}