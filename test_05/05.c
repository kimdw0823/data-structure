#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_DEGREE 101
typedef struct { 			// 다항식 구조체 타입 선언
	int degree;			// 다항식의 차수
	float coef[MAX_DEGREE];	// 다항식의 계수
} polynomial;
// 큐코드의 시작
#define MAX_QUEUE_SIZE 5

typedef polynomial element;
typedef struct { 				// 큐 타입
	int  front;
	int rear;
	element  data[MAX_QUEUE_SIZE];
} QueueType;

// 오류 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType *q)
{
	q->rear = -1;
	q->front = -1;
}


int is_full_for_queue(QueueType *q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}

int is_empty_for_queue(QueueType *q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

void enqueue(QueueType *q, polynomial item)
{
	if (is_full_for_queue(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	q->data[++(q->rear)] = item;
}

polynomial dequeue(QueueType *q)
{
	if (is_empty_for_queue(q)) {
		error("큐가 공백상태입니다.");
		
	}
	polynomial item = q->data[++(q->front)];
	return item;
}
//큐 코드의 끝
//다항식 덧셈코드 시작
#define MAX(a,b) (((a)>(b))?(a):(b))



// C=A+B 여기서 여기서 A와 B는 다항식이다. 구조체가 반환된다.
polynomial poly_add1(polynomial A, polynomial B)
{
	polynomial C;				// 결과 다항식
	int Apos = 0, Bpos = 0, Cpos = 0;	// 배열의 인덱스 변수
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); // 결과 다항식 차수

	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {  // A항>B항
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {  // A항== B항
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;
		}
		else {			// B항 > A항
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

void print_poly(polynomial p)
{
	for (int i = p.degree; i>0; i--)
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	printf("%3.1f \n", p.coef[p.degree]);
}
void fprintf_poly(polynomial p,FILE*fp)//파일에 다항식 출력
{
    for (int i = p.degree; i>0; i--)
    {   
        if((int)p.coef[p.degree - i]==0)
            continue;
        fprintf(fp,"%dx^%d + ", (int)p.coef[p.degree - i], i);
    }
		
	fprintf(fp,"%d \n", (int)p.coef[p.degree]);
}
//스택 코드이 시작()
#define MAX_STACK_SIZE 100

typedef polynomial element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType *s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty_for_stack(StackType *s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full_for_stack(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType *s, element item)
{
	if (is_full_for_stack(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType *s)
{
	if (is_empty_for_stack(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// 피크함수
element peek(StackType *s)
{
	if (is_empty_for_stack(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}
// 스택코드의 끝
int main(void)
{
    polynomial a={5,{10,0,0,0,6,3}};
    polynomial b={4,{1,0,5,0,7}};
    polynomial c={5,{9,0,0,0,6,2}};
    polynomial d={4,{1,0,5,0,7}};
    QueueType q;
    init_queue(&q);

    enqueue(&q,a);
    enqueue(&q,b);
    enqueue(&q,c);
    enqueue(&q,d);
    FILE *fp;
    fp=fopen("05-1.txt","w");
    polynomial temp;
    int i;
    fprintf(fp,"[다항식 1]\n");
    for(i=0;i<4;i++)
    {   
        if(i==2)
            fprintf(fp,"[다항식 2]\n");
        temp=dequeue(&q);
        fprintf_poly(temp,fp);
    }
    fclose(fp);
	system("notepad.exe 05-1.txt");

    polynomial sum_ab,sum_cd;
    sum_ab=poly_add1(a,b);
    sum_cd=poly_add1(c,d);
    
    StackType s;
    init_stack(&s);
    push(&s,sum_ab);
    push(&s,sum_cd);
    FILE *fp2;
    fp2=fopen("05-2.txt","w");
    fprintf(fp2,"[다항식 1의 결과]\n");
    for(i=0;i<2;i++)
    {   
        if(i==1)
            fprintf(fp2,"[다항식 2의 결과]\n");
        temp=pop(&s);
        fprintf_poly(temp,fp2);
    }
	fclose(fp2);
	system("notepad.exe 05-2.txt");

	

    

    return 0;
    



}   