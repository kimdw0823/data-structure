double slow_power(double x, int n)//거듭제곱 반복
{
	int i;
	double result = 1.0;

	for (i = 0; i<n; i++)
		result = result * x;
	return(result);
}