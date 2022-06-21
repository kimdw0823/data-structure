#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct DListNode {	// 이중연결 노드 타입
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

DListNode* current;

// 이중 연결 리스트를 초기화
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

// 이중 연결 리스트의 노드를 출력
void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		if (p == current)
			printf("<-| #%s# |-> ", p->data);
		else
			printf("<-| %s |-> ", p->data);
	}
	printf("\n");
}
// 노드 newnode를 노드 before의 오른쪽에 삽입한다.
void dinsert(DListNode *before, FILE*fp)
{
	DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
    fgets(newnode->data,100,fp);//fget으로 한줄씩 데이터를 파일로 부터 받는다

	//strcpy(newnode->data, data);
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}
// 노드 removed를 삭제한다.
void ddelete(DListNode* head,
	DListNode* removed)
{
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

// 이중 연결 리스트 테스트 프로그램
int main(void)
{   
    FILE *fp;//파일 포인터 생성
    fp=fopen("input.txt","r");//파일을 읽기 모드로 연다
	char ch;
	DListNode* head = (DListNode *)malloc(sizeof(DListNode));
	init(head);

	dinsert(head, fp);//매개변수로 파일 포인터를 준다
	dinsert(head, fp);
	dinsert(head, fp);

	current = head->rlink;
	print_dlist(head);

	do {
		printf("\n명령어를 입력하시오(<, >, q): ");
		ch = getchar();
		if (ch == '<') {
			current = current->llink;
			if (current == head)
				current = current->llink;
		}
		else if (ch == '>') {
			current = current->rlink;
			if (current == head)
				current = current->rlink;
		}
		print_dlist(head);
		getchar();
	} while (ch != 'q');
    fclose(fp);//파일 닫기
	free(head);// 동적 메모리 해제 코드를 여기에
    return 0;
}