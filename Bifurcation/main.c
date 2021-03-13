#include<stdio.h>
#include<omp.h>

double population_func(double x_n, double r)
{
        double growth_rate = r;
        return growth_rate*x_n*((double)1-x_n);
}


int main()
{
	double init_pop_size = 0.9;
	int nr_of_threads = 3;
	double max_growth_rate = 4.0;

	int nr_steps = (int)1e5;
	double step_size = max_growth_rate/((double)(nr_of_threads*nr_steps));
	#pragma omp parallel sections
	{
		#pragma omp section
		{
			double growth_rate = 0.0;
			for(int j = 1; j <= nr_steps; j++)
				{
				double pop_size = init_pop_size;
				for(int i = 1; i <= (int)1e3; i++)
					{
					pop_size = population_func(pop_size,growth_rate);
					}
				printf("%10g %10g \n",growth_rate,pop_size);
				growth_rate += step_size;		
				}
		}
		#pragma omp section
		{
			double growth_rate = 0.0;
			growth_rate += nr_steps*step_size;
			for(int j = 1; j <= nr_steps; j++)
				{
				double pop_size = init_pop_size;
				for(int i = 1; i <= (int)1e3; i++)
					{
					pop_size = population_func(pop_size,growth_rate);
					}
				printf("%10g %10g \n",growth_rate,pop_size);
				growth_rate += step_size;		
				}
		}
		#pragma omp section
		{
			double growth_rate = 0.0;
			growth_rate += 2.0*nr_steps*step_size;
			for(int j = 1; j <= nr_steps; j++)
				{
				double pop_size = init_pop_size;
				for(int i = 1; i <= (int)1e3; i++)
					{
					pop_size = population_func(pop_size,growth_rate);
					}
				printf("%10g %10g \n",growth_rate,pop_size);
				growth_rate += step_size;		
				}
		}
		
	}

}