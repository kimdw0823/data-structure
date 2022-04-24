#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
#define MAX 100 // 10의 승수 만큼 감소/증가 시켜 실험해볼 것

int black_cnt, red_cnt, blue_cnt, error_cnt, error_percent, total_cnt;
#define MAX_QUEUE_SIZE 101

typedef struct pen//생산된 펜들의 필드
{
	int pen_num;
	char pen_color[50];
	int pen_n;
	
	
}pen;
typedef struct pen_record// 생상된 팬들의 레코드
{
	pen p_record[100];
}pen_record;

typedef pen_record element;

typedef struct //원형큐 구조체
{ 
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

void error(char *message);//오류함수
void init_queue(QueueType *q);//초기화 함수
int is_empty(QueueType *q);//공백 상태 검출 함수
int is_full(QueueType *q);//포화 상태 검출 함수
void queue_print(QueueType *q,FILE*fp2);//운형큐 출력 함수
void enqueue(QueueType *q,element *pr);//삽입 함수
element dequeue(QueueType *q);//삭제 함수
element peek(QueueType *q);//피크 함수

int main()
{	
	pen p;
	pen_record pr;
	QueueType q;

	init_queue(&q);

	FILE *fp;
	FILE *fp2;
	fp=fopen("smart_factory.txt","a");
	fp2=fopen("smart_factory2.txt","a");
	if(fp==NULL||fp2==NULL)
		printf("파일 열기 실패");
	srand(time(NULL));

	const int error_percent = MAX * 5 / 100; // 5%의 불량률
	

	for (int i = 1; i <= MAX; i++)
	{

		int rand1 = rand();


		//printf("%03d개 볼펜생산 -> 볼펜번호%d\n\n", i, rand1);
		

		if (rand1 % 10 == 0)
		{
			red_cnt++;
			fprintf(fp,"%03d개 볼펜생산 -> 볼펜번호%d 볼펜색 -> 빨강\n\n ", i, rand1);
			strcpy(p.pen_color,"빨강");
		}	
		if (rand1 % 10 == 1)
		{
			blue_cnt++;
			fprintf(fp,"%03d개 볼펜생산 -> 볼펜번호%d 볼펜색 -> 파랑\n\n ", i, rand1);
			strcpy(p.pen_color,"파랑");
		}
		if ((rand1 % 10 >= 2) && (rand1 % 10 <= 9))
		{	
			black_cnt++;
			fprintf(fp,"%03d개 볼펜생산 -> 볼펜번호%d 볼펜색 -> 검정\n\n ", i, rand1);
			strcpy(p.pen_color,"검정");
		}	
		p.pen_n=i;
		p.pen_num=rand1;
		pr.p_record[i]=p;
		
		enqueue(&q,&pr);
		queue_print(&q,fp2);
		

	}
	total_cnt = black_cnt + red_cnt + blue_cnt;

	fprintf(fp,"\n\n총생산볼펜 %d=> 검%d, 빨%d, 파%d \n\n", total_cnt, black_cnt, red_cnt, blue_cnt);
	fprintf(fp,"불량률%d%%\n\n", error_percent);
	//printf("\n\n총생산볼펜 %d=> 검%d, 빨%d, 파%d \n\n", total_cnt, black_cnt, red_cnt, blue_cnt);
	//printf("불량률%d%%\n\n", error_percent);
	fclose(fp);
	fclose(fp2);
	

	return 0;
}
// 오류 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 초기화
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
void queue_print(QueueType *q,FILE*fp2)
{
	fprintf(fp2,"QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
			int i = q->front;
			do {
				i = (i + 1) % (MAX_QUEUE_SIZE);
				fprintf(fp2,"%d번째 생산 볼펜 볼펜번호:%d 볼펜색깔:%s| ", q->data[i].p_record[i].pen_n,q->data[i].p_record[i].pen_num,q->data[i].p_record[i].pen_color);
				if (i == q->rear)
					break;
			} while (i != q->front);
		}
	fprintf(fp2,"\n");
}

// 삽입 함수
void enqueue(QueueType *q,element *pr)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear]=*pr;
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