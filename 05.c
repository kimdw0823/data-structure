#include<stdio.h>
#include<stdlib.h>
//선현큐 코드 시작
#define MAX_QUEUE_SIZE 6
typedef int element;
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
void queue_print(QueueType *q)
{
	for (int i = 0; i<MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i> q->rear)
			printf("   | ");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}

int is_full(QueueType *q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}

int is_empty(QueueType *q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

void enqueue(QueueType *q, int item)
{
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	q->data[++(q->rear)] = item;
}

int dequeue(QueueType *q)

{
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		return -1;
	}
	int item = q->data[++(q->front)];
	return item;
}
//선형큐 코드 끝

//다항식 더하기 코드
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101
typedef struct { 			// 다항식 구조체 타입 선언
	int degree;			// 다항식의 차수
	float coef[MAX_DEGREE];	// 다항식의 계수
} polynomial;

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
//다항식 더하기 코드 끝
int main(void)
{
    QueueType q[4];

    int i;
    for(i=0;i<4;i++)
    {
        init_queue(&(q[i]));
    }

    enqueue(&(q[0]),10);
    enqueue(&(q[0]),0);
    enqueue(&(q[0]),0);
    enqueue(&(q[0]),0);
    enqueue(&(q[0]),6);
    enqueue(&(q[0]),3);//1  다항식 큐에 삽입

    enqueue(&(q[1]),0); 
    enqueue(&(q[1]),1); 
    enqueue(&(q[1]),0); 
    enqueue(&(q[1]),5); 
    enqueue(&(q[1]),0); 
    enqueue(&(q[1]),7);//2번 다항식 큐에 삽입

    enqueue(&(q[2]),9);  
    enqueue(&(q[2]),0);
    enqueue(&(q[2]),0);
    enqueue(&(q[2]),0);
    enqueue(&(q[2]),6);
    enqueue(&(q[2]),2);//3번 다항식 큐에 삽입

    enqueue(&(q[3]),0);
    enqueue(&(q[3]),1);
    enqueue(&(q[3]),0);
    enqueue(&(q[3]),5);
    enqueue(&(q[3]),0);
    enqueue(&(q[3]),7);//4번 다항식 큐에 삽입
    FILE *fp;
    fp=fopen("05-1.txt","w");
    fprintf(fp,"[다항식 1]\n");

    int item;
    int j;
    for(i=0;i<4;i++)
    {   
        
        if(i==2)
        {
            fprintf(fp,"[다항식 2]\n");
        }
        for(j=6;j>0;j--)
        {
            item=dequeue(&(q[i]));
            if(item!=0)
            {   if(j==1)
                {
                    fprintf(fp,"%d",item);

                    continue;
                }
                fprintf(fp,"%dx^%d+",item,j-1);
            }
            
        }
        fprintf(fp,"\n");        
    }
    for(i=0;i<4;i++)
    {
        q[i].front=-1;
    }
    polynomial a={5,{10,0,0,0,6,3}};
    polynomial b={4,{1,0,5,0,7}};
    polynomial c={5,{9,0,0,0,6,2}};
    polynomial d={4,{1,0,5,0,7}};
    polynomial sum_ab,sum_cd;
    sum_ab=poly_add1(a,b);
    sum_cd=poly_add1(c,d);



    

}