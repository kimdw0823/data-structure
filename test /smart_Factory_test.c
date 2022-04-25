#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define MAX 50 // 10의 승수 만큼 감소/증가 시켜 실험해볼 것

int black_cnt, red_cnt, blue_cnt, error_cnt, error_percent, total_cnt;
// ===== 원형큐 코드 시작 ======
#define MAX_QUEUE_SIZE 5

typedef struct arry
{
	int array[10];
}arry;
typedef arry element;

typedef struct { // 큐 타입

	element data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// 오류 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 공백 상태 검출 함수
void init_queue(QueueType *q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 원형큐 출력 함수
void queue_print(QueueType *q)
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
			int i = q->front;
			do {
				i = (i + 1) % (MAX_QUEUE_SIZE);
				printf("%d | ", q->data[i]);
				if (i == q->rear)
					break;
			} while (i != q->front);
		}
	printf("\n");
}

// 삽입 함수
void enqueue(QueueType *q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// 삭제 함수
element peek(QueueType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
// ===== 원형큐 코드 끝 ======

int main()
{   
	int manfuc_num=MAX;
    FILE *fp;
	FILE *fp2;
    fp=fopen("report.txt","a");
	fp2=fopen("report2.txt","a");

	QueueType q;
	init_queue(&q);

	srand(time(NULL));
	const int error_percent = MAX * 5 / 100; // 5%의 불량

	time_t timer;
	struct tm* t;
	timer=time(NULL);
	t=localtime(&timer);
	fprintf(fp,"%d년 %d월 %d일 %d시 %d분 %d초\n",t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min,t->tm_sec);
	

	for (int i = 1; i < MAX+1; i++)
	{

		int rand1 = rand();


		

		if (rand1 % 10 == 0)
			red_cnt++;
            
            fprintf(fp,"%03d개 볼펜생산 -> 볼펜번호%d 빨강\n\n", i, rand1);

		if (rand1 % 10 == 1)
			blue_cnt++;
            fprintf(fp,"%03d개 볼펜생산 -> 볼펜번호%d 파랑\n\n", i, rand1);

		if ((rand1 % 10 >= 2) && (rand1 % 10 <= 9))
			black_cnt++;
            fprintf(fp,"%03d개 볼펜생산 -> 볼펜번호%d 검정\n\n", i, rand1);

	}
	total_cnt = black_cnt + red_cnt + blue_cnt;
	
	fprintf(fp2,"%d %d %d %d %d\n",manfuc_num,red_cnt,blue_cnt,black_cnt,error_percent);
	fp2=fopen("report2.txt","r");
	int array[6];
	int i;
	for(i=0;i<5;i++)
	{
		fscanf(fp2,"%d",&(array[i]));
	}
	for(i=0;i<5;i++)
	{
		printf("%d ",array[i]);

	}
	enqueue(&q,arr)

	

	
	
	

    
    fprintf(fp,"\n\n총생산볼펜 %d=> 검%d, 빨%d, 파%d \n\n", total_cnt, black_cnt, red_cnt, blue_cnt);
	
	fprintf(fp,"불량갯수:%d개\n\n", error_percent);

	return 0;
}