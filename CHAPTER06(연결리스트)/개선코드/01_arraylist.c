#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define MAX_LIST_SIZE 100 	          // 리스트의 최대크기

typedef int element;			      // 항목의 정의
typedef struct {
	element array[MAX_LIST_SIZE];	  // 배열 정의
	int size;		                  // 현재 리스트에 저장된 항목들의 개수
} ArrayListType;

// 오류 처리 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 리스트 초기화 함수
void init(ArrayListType *L)
{
	L->size = 0;
}

// 리스트가 비어 있으면 1을 반환
// 그렇지 않으면 0을 반환
int is_empty(ArrayListType *L)
{
	return L->size == 0;
}

// 리스트가 가득 차 있으면 1을 반환
// 그렇지 많으면 1을 반환
int is_full(ArrayListType *L)
{
	return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType *L, int pos)
{
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	return L->array[pos];
}

// 리스트 출력
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
		error("리스트 오버플로우");
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
		error("위치 오류");
	item = L->array[pos];
	for (int i = pos; i<(L->size - 1); i++)
		L->array[i] = L->array[i + 1];
	L->size--;
	return item;
}
//연결리스트 코드시작
typedef struct ListNode { 	// 노드 타입
	element data;
	struct ListNode *link;
} ListNode;


ListNode* insert_first_linkedlist(ListNode *head, int value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	p->data = value;// (2)
	p->link = head;	// 헤드 포인터의 값을 복사	//(3)
	head = p;		// 헤드 포인터 변경		//(4)
	return head;	// 변경된 헤드 포인터 반환
}

// 노드 pre 뒤에 새로운 노드 삽입
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
// pre가 가리키는 노드의 다음 노드를 삭제한다. 
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
	fp=fopen("text1.txt","a+");//로그 기록을 남길 파일 생성후 열기

	time_t t=time(NULL);
	struct tm tm=*localtime(&t);//현재시간 출력을 위한 코드
	fprintf(fp,"실행시각: %d년 %d월 %d일 %d시 %d분\n",tm.tm_year+1900,tm.tm_mon+1,tm.tm_mday,tm.tm_hour,tm.tm_min);
	//파일에 로그 시간을 기록한다
	clock_t start, stop;
	double  duration;
	start = clock();	// 측정 시작

	// ArrayListType를 정적으로 생성하고 ArrayListType를 	
	// 가리키는 포인터를 함수의 매개변수로 전달한다.
	ArrayListType list;

	init(&list);		
	insert(&list, 0, 10);	print_list(&list);	// 0번째 위치에 10 추가
	insert(&list, 0, 20);	print_list(&list);	// 0번째 위치에 20 추가
	insert(&list, 0, 30);	print_list(&list);	// 0번째 위치에 30 추가
	insert_last(&list, 40);	print_list(&list);	// 맨 끝에 40 추가
	delete(&list, 0);		print_list(&list);	// 0번째 항목 삭제
	
	stop = clock();	// 측정 종료
	duration = (double)(stop - start) / CLOCKS_PER_SEC;
	
	fprintf(fp,"배열 리스트 수행시간: %lf\n",duration);

	start = clock();	// 측정 시작
	//같은 크기와 같은 위치에 똑같이 삽입하는 연결리스트 코드
	ListNode*head=NULL;

	head=insert_first_linkedlist(head,10);//0번째 위치에 10 추가
	print_linkedlist(head);
	head=insert_first_linkedlist(head,20);//0번째 위치에 20 추가
	print_linkedlist(head);
	head=insert_first_linkedlist(head,30);//0번째 위치에 30 추가
	print_linkedlist(head);
	insert_linkedlist(head,head->link->link,40);//맨 끝에 40추가
	print_linkedlist(head);
	head=delete_first_linkedlist(head);
	print_linkedlist(head); 

	stop = clock();	// 측정 종료
	duration = (double)(stop - start) / CLOCKS_PER_SEC;

	fprintf(fp,"연결리스트 수행시간: %lf\n",duration);

	free(head);//메모리 해제
	fclose(fp);//파일 닫기	

	return 0;
}