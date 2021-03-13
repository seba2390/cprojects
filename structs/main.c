#include <stdio.h>  
#include <stdlib.h>  

struct quad_vals {double* p; double* c;};
typedef struct quad_vals quad_vals;


quad_vals test(int size, double xs[], quad_vals vals)
{
    for(int i = 0; i < size; i++)
	{
		vals.p[i]=xs[i];
		vals.c[i]=xs[i]*0.5;
	}
		return vals;
}

int main()
{
	double xs[] = {1,2,3,4,5};
	double cvals[5];
	double pvals[5];
	quad_vals init_values = {cvals, pvals};
	quad_vals final_values = test(5,xs,init_values);
	
	for(int i = 0; i < 5;i++)
	{
		printf("%10g %10g\n",final_values.c[i],final_values.p[i]);
	}
}