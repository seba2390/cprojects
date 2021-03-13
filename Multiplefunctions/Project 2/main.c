#include<stdio.h>

void main()
{
	int sum_numbers(int num1, int num2)
		{
			return num1 + num2;
		}

	int num1, num2;

	printf("Enter the first integer:");
	scanf("%d", &num1);
	printf("Enter the second integer:");
	scanf("%d", &num2);

	int result = sum_numbers(num1,num2);

	printf("The sum is: %d\n",result);
}
