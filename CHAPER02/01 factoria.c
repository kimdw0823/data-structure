int factorial(int n)//팩토리얼 순환으로 
{
    //printf("factorial(%d)\n",n);
    if( n <= 1 ) return(1);
    else return (n * factorial(n-1) );
}