#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 10
// ��������
int list[MAX_SIZE];
int n;
void insertion_sort(int list[], int n)//(����Ʈ,����Ʈ ũ��)
{
	int i, j, key;
	for (i = 1; i<n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j]>key; j--)
			list[j + 1] = list[j]; /* ���ڵ��� ������ �̵� */
		list[j + 1] = key;
	}
}
int main(void)
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for (i = 0; i<n; i++)      	// ���� ���� �� ��� 
		list[i] = rand() % 100; // ���� �߻� ���� 0~99

	insertion_sort(list, n); // �������� ȣ�� 
	for (i = 0; i<n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}