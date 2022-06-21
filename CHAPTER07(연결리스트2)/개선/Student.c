#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>


typedef struct ListNode 
{ 	// 노드 타입
	int id;
    char name[10];
    double grade;
	struct ListNode *link;
} ListNode;

// 리스트의 항목 출력
void print_list(ListNode* head)
{
	ListNode* p;
	printf("학번 이름   성적\n");
	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d    %s %.1lf\n",p->id,p->name,p->grade);
		p = p->link;
	} while (p != head);
	printf("%d    %s %.1lf\n",p->id,p->name,p->grade);
}

ListNode* insert_first(ListNode* head, int id,char* name,double grade)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));//레코드 동적할당
	node->id = id;//학번 저장
    node->grade=grade;//학점 저장
    strcpy(node->name,name);//이름저장
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;		// (2)
	}
	return head;	// 변경된 헤드 포인터를 반환한다. 
}

ListNode* insert_last(ListNode* head, int id,char* name,double grade)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));//레코드 동적 할당
	node->id = id;//학번 저장
    node->grade=grade;//학점 저장
    strcpy(node->name,name);//이름 저장
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;		// (2)
		head = node;		// (3)
	}
	return head;	// 변경된 헤드 포인터를 반환한다. 
}
void serch_grade(ListNode* head)//3.5 이하의 학생을 찾는 함수
{
	printf("학점이 3.5 이하인 학생은\n");
	printf("학번 이름   성적\n");
	
	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do {
		if(p->grade<=3.5)
		{
			printf("%d    %s %.1lf\n",p->id,p->name,p->grade);
		}
		p = p->link;
	} while (p != head);
	if(p->grade<=3.5)
		{
			printf("%d    %s %.1lf\n",p->id,p->name,p->grade);
		}
}


int main(void)
{
    ListNode *head=NULL;
	
	head=insert_first(head,4,"김도우",3.9);
	head=insert_first(head,3,"김도우",2.5);
	head=insert_first(head,2,"김도우",1.5);
	head=insert_first(head,1,"김도우",3.8);
	head=insert_last(head,5,"김도우",4.5);
	print_list(head);
	serch_grade(head);

    return 0;
}