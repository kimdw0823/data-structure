double power(double x, int n)//거듭제곱 순환
{
	if( n==0 ) return 1;
	else if ( (n%2)==0 ) 
		return power(x*x, n/2);
	else return x*power(x*x, (n-1)/2);
}