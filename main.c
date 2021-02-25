#include<stdio.h>

double population_func(double x_n, double r)
{
        double growth_rate = r;
        return growth_rate*x_n*(1.0-x_n);
}


int main()
{
	
	double init_pop_size = 0.5;
	double growth_rate = 0.0;
	double max_growth_rate = 4.0;

	double nr_steps = 1000000;
	double step_size = max_growth_rate/nr_steps;
	double tolerance = 1.0e-13;
	
	for(int j = 1; j <= nr_steps; j++)
	{
		double pop_size = init_pop_size;
		for(int i = 1; i <= 1000; i++)
		{
		pop_size = population_func(pop_size,growth_rate);
		if(pop_size<tolerance)
			{
				pop_size = 0.0;
			}
		}
		printf("%10g %10g \n",growth_rate,pop_size);
		growth_rate += step_size;		
	}

}