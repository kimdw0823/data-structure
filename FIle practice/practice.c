#include<stdio.h>

int main(void)
{
    FILE *fp=fopen("test,txt","a+");
    
    char name[60];

    fprintf(fp,"hello world");

    fclose(fp);
    return 0;

}