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
    fp=fopen("01.txt","wb");
    student s[10]=
    {
        {"김도우",1},{"성태훈",2},{"김학선",3},{"장원진",4},{"방석진",5}
        ,{"김윤희",6},{"김진숙",7},{"안상현",8},{"김혜빈",9},{"유준선",10}
    };
    srand(time(NULL));
    float k;
    fprintf(fp,"이름 학번 성적\n");
    
    int i;
    for(i=0;i<10;i++)
    {   
        k = (float)(rand()%50) / 10;
        s[i].grade=k;
    }
    fwrite(&s, sizeof(s), 1, fp); 

    
    fclose(fp);
    return 0;
    
}