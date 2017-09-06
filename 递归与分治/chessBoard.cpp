//���̸�������
/*
(tr��tc)���������Ͻǵķ�������
(dr,dc)�����ⷽ�����ڵ�����
size�����̵Ĵ�С������������
*/
#include<iostream>
using namespace std;
int board[1025][1025];
static int tile = 1;

void ChessBoard(int tr, int tc, int dr, int dc, int size)
{
	if (size == 1) return;//�ݹ�߽� 

	int t = tile++;//L�͹��ƺ� 
	int s = size / 2;//�ָ����� 
	//�������Ͻ������� 
	if (dr<tr + s && dc<tc + s)
		ChessBoard(tr, tc, dr, dc, s);//���ⷽ���ڴ������� 
	else //�������������ⷽ����t��L�͹��Ƹ������½� 
	{
		board[tr + s - 1][tc + s - 1] = t;
		//�������෽�� 
		ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
	}
	//�������Ͻ������� 
	if (dr<tr + s && dc >= tc + s)
		ChessBoard(tr, tc + s, dr, dc, s);//���ⷽ���ڴ�������
	else //�������������ⷽ����t��L�͹��Ƹ������½� 
	{
		board[tr + s - 1][tc + s] = t;
		//�������෽�� 
		ChessBoard(tr, tc + s, tr + s - 1, tc + s, s);
	}
	//�������½������� 
	if (dr >= tr + s && dc<tc + s)//���ⷽ���ڴ�������
		ChessBoard(tr + s, tc, dr, dc, s);
	else //�������������ⷽ����t��L�͹��Ƹ������Ͻ� 
	{
		board[tr + s][tc + s - 1] = t;
		//�������෽�� 
		ChessBoard(tr + s, tc, tr + s, tc + s - 1, s);
	}
	//�������½������� 
	if (dr >= tr + s && dc >= tc + s)//���ⷽ���ڴ�������
		ChessBoard(tr + s, tc + s, dr, dc, s);
	else //�������������ⷽ����t��L�͹��Ƹ������Ͻ� 
	{
		board[tr + s][tc + s] = t;
		//�������෽�� 
		ChessBoard(tr + s, tc + s, tr + s, tc + s, s);
	}
}

int main()
{
	/*int i, j;
	int k;
	while (cin >> k)
	{
		int size = 1 << k;
		int x, y;
		cin >> x >> y;
		board[x][y] = 0;
		ChessBoard(0, 0, x, y, size);
		for (i = 0; i<size; i++)
		{
			for (j = 0; j < size; j++)
				cout << board[i][j] << "\t";
			cout << "\n";
		}
	}*/

	int i, j, x, y;
	int size;
	printf("input the size of chess:\n");
	scanf("%d", &size);
	printf("input the orignal position of special point:\n");
	scanf("%d%d", &x,&y);
	ChessBoard(0, 0, x, y, size);
	for (i = 0; i<size; i++)
	{
		for (j = 0; j < size; j++)
			printf("%d ", board[i][j]);
		printf("\n");
	}
	return 0;
}