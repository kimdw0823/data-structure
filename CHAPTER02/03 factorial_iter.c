int factorial_iter(int n)//팩토리얼 반복
{
    int i, result = 1;
    for(i=1; i<=n; i++)
        result = result * i;
    return(result);
}