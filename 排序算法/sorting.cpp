#include<stdio.h>

int toSort[100];
int n = 0;  // the length of toSort
int whichsort;

void input();
void bubbleSort();
void insertionSort();
void selectionSort();
void quickSort(int left, int right);



int main()
{
	int k;
	input();
	printf("which sort theory to use:\n");
	printf("1 bubble    sort\n");
	printf("2 insert    sort\n");
	printf("3 selectuon sort\n");
	printf("4 quick     sort\n");
	scanf("%d", &whichsort);

	for (k = 0; k < n; k++)
		printf("%d ", toSort[k]);
	printf("\n");

	if (whichsort == 1)
		bubbleSort();
	else if (whichsort == 2)
		insertionSort();
	else if (whichsort == 3)
		selectionSort(); 
	else if (whichsort == 4)
		quickSort(0, n - 1);
	else;

	return 0;
}

void input()
{
	int i=0;
	printf("input the length of the array to be sorted:\n");
	scanf("%d", &n);
	printf("input the array to be sorted:\n");
	for (i = 0; i<n; i++)
		scanf("%d", &toSort[i]);
}

void bubbleSort()
{
	int i, j, k, m;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (toSort[j]>toSort[j + 1])
			{
				m = toSort[j];
				toSort[j] = toSort[j + 1];
				toSort[j + 1] = m;
			}
			for (k = 0; k < n; k++)
				printf("%d ", toSort[k]);
			printf("\n");
		}
	}
}

void insertionSort()
{
	int i, j, k, m;
	for (i = 0; i < n - 1; i++)
	{
		j = i;
		m = toSort[i + 1];
		while (m < toSort[j] && j >= 0)
		{
			toSort[j + 1] = toSort[j];
			j--;
		}
		toSort[j + 1] = m;
		for (k = 0; k < n; k++)
			printf("%d ", toSort[k]);
		printf("\n");
	}
}

void selectionSort()
{
	int i, j, m, k;
	for (i = 0; i < n - 1; i++)
	{
		m = toSort[i];
		for (j = i; j < n ; j++)
		{
			if (toSort[j] < m)
			{
				m = toSort[j];
				k = j;
			}
		}
		toSort[k] = toSort[i];
		toSort[i] = m;
		for (k = 0; k < n; k++)
			printf("%d ", toSort[k]);
		printf("\n");
	}
}

void quickSort(int left,int right)
{
	int i, j, k, m;
	if (left < right)
	{
		i = left;
		j = right + 1;
		while (i < j)
		{
			while (i < right&&toSort[++i] < toSort[left]);
			while (j>left&&toSort[--j] > toSort[left]);
			if (i < j)
			{
				m = toSort[i];
				toSort[i] = toSort[j];
				toSort[j] = m;
			}
		}
		m = toSort[left];
		toSort[left] = toSort[j];
		toSort[j] = m;
		for (k = 0; k < n; k++)
			printf("%d ", toSort[k]);
		printf("\n");
		quickSort(left, j - 1);
		quickSort(j + 1, right);
	}
}