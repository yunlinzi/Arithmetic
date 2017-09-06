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
{ // 将两个已经排好序的数组合并，两个数组分别为：
  // str1[first:middle] 、 str1[middle+1:end]
  // 排好序后存入str2

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
{ // 将str1递归地分割，待两部分都有序（即都只剩一个数据）
  // 后调用mergeArray进行合并,最终存储在str2中

	int middle, str[10001];
	if (first == end)str2[first] = str1[first]; // str1只有一个数据、这也是分割的终点
	else
	{
		middle = (first + end) / 2;
		mergeSort(str1, str, first, middle);   // 左边最终排好序存在str[first:middle]中
		mergeSort(str1, str, middle + 1, end);  // 右边最终排好序存在str[middle+1:end]中
		mergeArray(str, str2, first, middle, end); // 合并 str1[first:middle] 、 str1[middle+1:end] 到 str2中
	}
}
