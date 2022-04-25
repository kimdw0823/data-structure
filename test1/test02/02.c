#include<stdio.h>
#include<time.h>
#include<stdlib.h>
typedef struct student
{
    char name[10];
    int student_num;
    float grade;

}student;

int main(void)
{   
    FILE *fp;
    fp=fopen("02.txt","w");
    student s[10]=
    {
        {"김도우",1},{"성태훈",2},{"김학선",3},{"장원진",4},{"방석진",5}
        ,{"김윤희",6},{"김진숙",7},{"안상현",8},{"김혜빈",9},{"유준선",10}
    };
    srand(time(NULL));
    float k;
    
    int i;
    for(i=0;i<10;i++)
    {   
        k = (float)(rand()%50) / 10;
        s[i].grade=k;
    }

    for(i=0;i<10;i++)

    {
        fprintf(fp,"%s %d %lf\n",s[i].name,s[i].student_num,s[i].grade);
    }
    fclose(fp);
    system("notepad.exe 02.txt");

}