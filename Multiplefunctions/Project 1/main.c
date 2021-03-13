
#include <stdio.h>
#include "factorial.h"

void main()
{
	int number;
        printf("Enter an integer:");
        scanf("%d", &number);
	unsigned long long int result = ftorial(number);
	printf("The factorial of %d is:\n", number);
	printf("%llu\n",result);
}
