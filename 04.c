#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_SIZE 5
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

typedef struct student
{	
	int record_num;
	char id[20];
	char name[10];
	double score;
	int grade;
}student;

typedef struct ListNode { 	// 노드 타입
	student data;
	struct ListNode *link;
} ListNode;

ListNode* list[MAX_SIZE];
int n=MAX_SIZE;
int in_dex=0;
void selection_sort(ListNode* list[], int n)//(리스트,리스트 크기)
{
	int i, j, least;
	ListNode* temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) 	// 최소값 탐색
			if (list[j]->data.score < list[least]->data.score) least = j;
		
		SWAP(list[i], list[least], temp);
	}
	j=1;
	for(i=4;i>=0;i--)
	{
		list[i]->data.grade=j;
		j++;
	}
}
// 오류 처리 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode *head,int record_num,char* id,char *name,double score)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	p->data.record_num=record_num;
	strcpy(p->data.id,id);
	strcpy(p->data.name,name);
	
	p->data.score=score;
	p->link=head;
	head = p;
	list[in_dex++]=p;	     // 헤드 포인터 변경		//(4)
	return head;	// 변경된 헤드 포인터 반환
}

// 노드 pre 뒤에 새로운 노드 삽입
ListNode*  insert(ListNode *head, ListNode *pre,int record_num,char* id,char *name,double score)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	strcpy(p->data.id,id);
	p->data.record_num=record_num;
	strcpy(p->data.name,name);
	
	p->data.score=score;
	p->link = pre->link;	//(3)	
	pre->link = p;		//(4)	
	list[in_dex++]=p;	
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
// pre가 가리키는 노드의 다음 노드를 삭제한다. 
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
		fprintf(fp,"  %d     %s    %s   %.2lf   %d\n", p->data.record_num,p->data.id,p->data.name,p->data.score,p->data.grade);
	
}
ListNode* search_record(ListNode *head, char* id)//리스트 검색 코드
{
	ListNode *p = head;

	while (p != NULL) {
		if (!strcmp(p->data.id,id)) return p;
		p = p->link;
	}
	return NULL;	// 탐색 실패
}
//void serch_id();

// 테스트 프로그램
int main(void)
{
	ListNode *head = NULL;
	head=insert_first(head,1,"2020131055","ojm",3.82);
	insert(head,head,2,"2020131011","sjm",3.99);
	insert(head,head->link,3,"2020132044","ajm",4.3);
	insert(head,head->link->link,4,"2020132033","yjm",4.2);
	insert(head,head->link->link->link,5,"2020132022","bjm",4.25);

	selection_sort(list,n);
	FILE*fp;
	fp=fopen("04.txt","w");
	fprintf(fp,"레코드번호    학번        이름   학점   등수\n");
	fprint_list(head,fp);
	fclose(fp);
	while(1)
	{
		char *id;
		ListNode* record;
		printf("학번:");
		scanf("%s",id);
		if(!strcmp(id,"q"))
			break;

		record=search_record(head,id);
		if(record==NULL)
		{
			printf("없는 학번\n");
			continue;
		}
			
		printf("학점  등수\n");
		printf("%.2lf   %d\n",record->data.score,record->data.grade);
	}
	
	for(int i=0;i<5;i++)
	{
		head=delete_first(head);
	}
	free(head);
	return 0;
}