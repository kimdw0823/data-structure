#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define MAX 50 // 10의 승수 만큼 감소/증가 시켜 실험해볼 것

int black_cnt, red_cnt, blue_cnt, error_cnt, error_percent, total_cnt;

int main()
{   
    FILE *fp;
    fp=fopen("report.txt","a");
	srand(time(NULL));
	const int error_percent = MAX * 5 / 100; // 5%의 불량갯수
	

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

    
    fprintf(fp,"\n\n총생산볼펜 %d=> 검%d, 빨%d, 파%d \n\n", total_cnt, black_cnt, red_cnt, blue_cnt);
	
	fprintf(fp,"불량갯수:%d개\n\n", error_percent);

	return 0;
}