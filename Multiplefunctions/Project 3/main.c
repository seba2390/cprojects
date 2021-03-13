#include <stdio.h>
#include "power.h"

void main()
{
	int base, powern;
	printf("Enter the base number:");
	scanf("%d", &base);
	printf("Enter the power:");
	scanf("%d", &powern);
	long int result = power(base,powern);
	printf("The result is: %li\n", result);
}
