

long int power(int base, int power)
{
	long int result = base;
	for(int i = 1; i < power-1; i++)
	{
		result = result*base;
	}
	return result;
}
