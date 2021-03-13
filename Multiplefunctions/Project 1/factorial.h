

/******************************
*****factorial function************
******************************/

unsigned long long int ftorial(int number)
{
	int temp = number;
	unsigned long long int result = 1;
	for(int i =1; i<=number; i++)
		{
			result = result*i;
		}
	return result;
}

