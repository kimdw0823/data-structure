#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX];
int n;
void bubble_sort(int list[], int n)//(����Ʈ,����Ʈ ũ��)
{
	int i, j, temp;
	for (i = n - 1; i>0; i--) {
		for (j = 0; j<i; j++)
			/* �յ��� ���ڵ带 ���� �� ��ü */
			if (list[j]>list[j + 1])
				SWAP(list[j], list[j + 1], temp);
	}
}
int main(void)
{
	n=MAX;
	int i;
	srand(time(NULL));
	for(i=0;i<n;i++)
	{
		list[i] = rand() % 100;
	}
	bubble_sort(list,n);
	for (i=0;i<n;i++)
	{
		printf("%d ",list[i]);
	}
}