#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef int element;
typedef struct student
{	
	int id;
	char name[10];
	char phone_num[20];
	double grad;
}student;
typedef struct ListNode { 	// ��� Ÿ��
	student data;
	struct ListNode *link;
} ListNode;

// ���� ó�� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode *head, char *name,double grade,char* phone_num,int id)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	p->data.id=id;
	strcpy(p->data.name,name);
	strcpy(p->data.phone_num,phone_num);
	p->data.grad=grade;
	p->link=head;
	head = p;		// ��� ������ ����		//(4)
	return head;	// ����� ��� ������ ��ȯ
}

// ��� pre �ڿ� ���ο� ��� ����
ListNode*  insert(ListNode *head, ListNode *pre,char *name,double grade,char* phone_num,int id)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	p->data.id=id;
	strcpy(p->data.name,name);
	strcpy(p->data.phone_num,phone_num);
	p->data.grad=grade;
	p->link = pre->link;	//(3)	
	pre->link = p;		//(4)	
	return head;		//(5)	
}

ListNode* delete_first(ListNode *head)
{
	ListNode *removed;
	if (head == NULL) return NULL;
	removed = head;	// (1)
	head = removed->link;	// (2)
	free(removed);		// (3)
	return head;		// (4)
}
// pre�� ����Ű�� ����� ���� ��带 �����Ѵ�. 
ListNode* delete(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link;
	pre->link = removed->link;		// (2)
	free(removed);			// (3)
	return head;			// (4)
}

void fprint_list(ListNode *head,FILE*fp)
{
	for (ListNode *p = head; p != NULL; p = p->link)
		fprintf(fp,"%d   %s    %s         %.1lf\n", p->data.id,p->data.name,p->data.phone_num,p->data.grad);
	
}

// �׽�Ʈ ���α׷�
int main(void)
{
	ListNode *head = NULL;
	head=insert_first(head,"kim ",4.5,"010123456789",5);
	head=insert_first(head,"lee ",3.5,"010123456789",4);
	head=insert_first(head,"park",2.5,"010123456789",3);
	head=insert_first(head,"na  ",1.5,"010123456789",1);
	insert(head,head,"hyun",4.1,"010123456789",2
	
	
	
	);
	FILE*fp;
	fp=fopen("text2.txt","w");
	fprintf(fp,"�й� �̸�       ��ȭ��ȣ           ����\n");
	fprint_list(head,fp);
	fclose(fp);
	free(head);

	
}