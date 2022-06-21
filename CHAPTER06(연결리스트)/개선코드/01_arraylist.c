#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define MAX_LIST_SIZE 100 	          // ����Ʈ�� �ִ�ũ��

typedef int element;			      // �׸��� ����
typedef struct {
	element array[MAX_LIST_SIZE];	  // �迭 ����
	int size;		                  // ���� ����Ʈ�� ����� �׸���� ����
} ArrayListType;

// ���� ó�� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ����Ʈ �ʱ�ȭ �Լ�
void init(ArrayListType *L)
{
	L->size = 0;
}

// ����Ʈ�� ��� ������ 1�� ��ȯ
// �׷��� ������ 0�� ��ȯ
int is_empty(ArrayListType *L)
{
	return L->size == 0;
}

// ����Ʈ�� ���� �� ������ 1�� ��ȯ
// �׷��� ������ 1�� ��ȯ
int is_full(ArrayListType *L)
{
	return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType *L, int pos)
{
	if (pos < 0 || pos >= L->size)
		error("��ġ ����");
	return L->array[pos];
}

// ����Ʈ ���
void print_list(ArrayListType *L)
{
	int i;
	for (i = 0; i<L->size; i++)
		printf("%d->", L->array[i]);
	printf("\n");
}

void insert_last(ArrayListType *L, element item)
{
	if( L->size >= MAX_LIST_SIZE ) {
		error("����Ʈ �����÷ο�");
	}
	L->array[L->size++] = item;
}
void insert(ArrayListType *L, int pos, element item)
{
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--)
			L->array[i + 1] = L->array[i];
		L->array[pos] = item;
		L->size++;
	}
}
element delete(ArrayListType *L, int pos)
{
	element item;

	if (pos < 0 || pos >= L->size)
		error("��ġ ����");
	item = L->array[pos];
	for (int i = pos; i<(L->size - 1); i++)
		L->array[i] = L->array[i + 1];
	L->size--;
	return item;
}
//���Ḯ��Ʈ �ڵ����
typedef struct ListNode { 	// ��� Ÿ��
	element data;
	struct ListNode *link;
} ListNode;


ListNode* insert_first_linkedlist(ListNode *head, int value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	p->data = value;// (2)
	p->link = head;	// ��� �������� ���� ����	//(3)
	head = p;		// ��� ������ ����		//(4)
	return head;	// ����� ��� ������ ��ȯ
}

// ��� pre �ڿ� ���ο� ��� ����
ListNode*  insert_linkedlist(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	p->data = value;		//(2)
	p->link = pre->link;	//(3)	
	pre->link = p;		//(4)	
	return head;		//(5)	
}

ListNode* delete_first_linkedlist(ListNode *head)
{
	ListNode *removed;
	if (head == NULL) return NULL;
	removed = head;	// (1)
	head = removed->link;	// (2)
	free(removed);		// (3)
	return head;		// (4)
}
// pre�� ����Ű�� ����� ���� ��带 �����Ѵ�. 
ListNode* delete_linkedlist(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link;
	pre->link = removed->link;		// (2)
	free(removed);			// (3)
	return head;			// (4)
}

void print_linkedlist(ListNode *head)
{
	for (ListNode *p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

int main(void)
{	
	
	FILE *fp;
	fp=fopen("text1.txt","a+");//�α� ����� ���� ���� ������ ����

	time_t t=time(NULL);
	struct tm tm=*localtime(&t);//����ð� ����� ���� �ڵ�
	fprintf(fp,"����ð�: %d�� %d�� %d�� %d�� %d��\n",tm.tm_year+1900,tm.tm_mon+1,tm.tm_mday,tm.tm_hour,tm.tm_min);
	//���Ͽ� �α� �ð��� ����Ѵ�
	clock_t start, stop;
	double  duration;
	start = clock();	// ���� ����

	// ArrayListType�� �������� �����ϰ� ArrayListType�� 	
	// ����Ű�� �����͸� �Լ��� �Ű������� �����Ѵ�.
	ArrayListType list;

	init(&list);		
	insert(&list, 0, 10);	print_list(&list);	// 0��° ��ġ�� 10 �߰�
	insert(&list, 0, 20);	print_list(&list);	// 0��° ��ġ�� 20 �߰�
	insert(&list, 0, 30);	print_list(&list);	// 0��° ��ġ�� 30 �߰�
	insert_last(&list, 40);	print_list(&list);	// �� ���� 40 �߰�
	delete(&list, 0);		print_list(&list);	// 0��° �׸� ����
	
	stop = clock();	// ���� ����
	duration = (double)(stop - start) / CLOCKS_PER_SEC;
	
	fprintf(fp,"�迭 ����Ʈ ����ð�: %lf\n",duration);

	start = clock();	// ���� ����
	//���� ũ��� ���� ��ġ�� �Ȱ��� �����ϴ� ���Ḯ��Ʈ �ڵ�
	ListNode*head=NULL;

	head=insert_first_linkedlist(head,10);//0��° ��ġ�� 10 �߰�
	print_linkedlist(head);
	head=insert_first_linkedlist(head,20);//0��° ��ġ�� 20 �߰�
	print_linkedlist(head);
	head=insert_first_linkedlist(head,30);//0��° ��ġ�� 30 �߰�
	print_linkedlist(head);
	insert_linkedlist(head,head->link->link,40);//�� ���� 40�߰�
	print_linkedlist(head);
	head=delete_first_linkedlist(head);
	print_linkedlist(head); 

	stop = clock();	// ���� ����
	duration = (double)(stop - start) / CLOCKS_PER_SEC;

	fprintf(fp,"���Ḯ��Ʈ ����ð�: %lf\n",duration);

	free(head);//�޸� ����
	fclose(fp);//���� �ݱ�	

	return 0;
}