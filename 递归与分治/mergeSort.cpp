#include<stdio.h>

void mergeArray(int str1[], int str2[], int first, int middle, int end);
void mergeSort(int str1[], int str2[], int first, int end);

int main()
{
	int i, n, str1[10001], str2[10001];
	printf("input the size of string:\n");
	scanf("%d", &n);
	printf("input the string:\n");
	for (i = 0; i<n; i++)
	{
		scanf("%d", &str1[i]);
	}
	
	mergeSort(str1, str2, 0, n - 1);
	printf("output the string:\n");
	for (i = 0; i<n; i++)	
		printf("%d ", str2[i]);
	printf("\n");
	return 0;
}




void mergeArray(int str1[], int str2[], int first, int middle, int end)
{ // �������Ѿ��ź��������ϲ�����������ֱ�Ϊ��
  // str1[first:middle] �� str1[middle+1:end]
  // �ź�������str2

	int k = first;
	int i = first, j = middle + 1;

	while (i <= middle&&j <= end)
	{
		if (str1[i] < str1[j])
			str2[k++] = str1[i++];
		else
			str2[k++] = str1[j++];
	}

	while (i <= middle)str2[k++] = str1[i++];

	while (j <= end)str2[k++] = str1[j++];
}

void mergeSort(int str1[], int str2[], int first, int end)
{ // ��str1�ݹ�طָ�������ֶ����򣨼���ֻʣһ�����ݣ�
  // �����mergeArray���кϲ�,���մ洢��str2��

	int middle, str[10001];
	if (first == end)str2[first] = str1[first]; // str1ֻ��һ�����ݡ���Ҳ�Ƿָ���յ�
	else
	{
		middle = (first + end) / 2;
		mergeSort(str1, str, first, middle);   // ��������ź������str[first:middle]��
		mergeSort(str1, str, middle + 1, end);  // �ұ������ź������str[middle+1:end]��
		mergeArray(str, str2, first, middle, end); // �ϲ� str1[first:middle] �� str1[middle+1:end] �� str2��
	}
}
