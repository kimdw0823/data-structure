#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//#define NUM 3//원판의 갯수를 바꾸기 위한 장치
void hanoi_tower(int n, char from, char tmp, char to);
int main(void)
{   
    FILE*fp;
    fp=fopen("04.txt","w");
    int i;
    for(i=1;i<15;i++)
    {
        fprintf(fp,"원판의 개수 %d\n",i);
    }
    fprintf(fp,"----------------------------------\n");
	clock_t start,stop;//수행 시간 측정을 위한 변수 선언
    double duration;//수행시간을 저장할 변수
    for(i=1;i<15;i++)
    {
        start=clock();//시작 시간 측정


	    hanoi_tower(i, 'A', 'B', 'C');

	    stop=clock();//종류 시간 측정
        duration=(double)(stop-start)/CLOCKS_PER_SEC;//수행시간 구하기

        if(i>=10)
        {
            fprintf(fp,"원판의 개수 %d 수행시간:%lf\n",i,duration);
        }
        else
        {
            fprintf(fp,"원판의 개수 %d\n",i);
        }
        //printf("수행시간: %lf",duration);//수행시간 출력
    }
   
    return 0;
    
}
void hanoi_tower(int n, char from, char tmp, char to)
{	
	
	if( n==1 ) ;
	else {
		hanoi_tower(n-1, from, to, tmp);
		
		hanoi_tower(n-1, tmp, from, to);
	}
}

