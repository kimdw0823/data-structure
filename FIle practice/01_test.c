#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* p; // 파일 포인터 생성
	int a;
	char b[40];
	double c;
	
	p = fopen("/Users/kimdowoo/Documents/GitHub/data-structure/FIle practice/report.txt", "r"); // 1. 기존 파일이 존재하면, read 모드로 파일 읽기
	
	if (p == NULL)
		printf("파일오픈 에러\n");

	fscanf(p,"%d %s %lf",&a,b,&c);
	printf("%d %s %lf",a,b,c);
	fclose(p);

	system("notepad.exe /Users/kimdowoo/Documents/GitHub/data-structure/FIle practice/report.txt");
	//system("notepad.exe D:\\report1.txt");

	return 0;
	
	
}
