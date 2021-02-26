#include <stdio.h> 
#include <math.h>

#define BG_V 0.015
#define INPUT_V 4.037

int main(int argc, char *argv[])  {  
	double value;
	FILE* my_in_stream = fopen(argv[1],"r");
	FILE* my_out_stream = fopen("out.txt","w");
	int count=0;
	//fprintf(my_out_stream,"################################\n");
	//fprintf(my_out_stream,"Labeled values listed below:\n");
	while(fscanf(my_in_stream,"%lg",&value)!=EOF){
		if(count==1)
		{
			count -= 1;
			double output = value-BG_V;			
			fprintf(my_out_stream,"%15g\n",output/INPUT_V);
		}
		else
		{
		count++;
		fprintf(my_out_stream,"%g",value);
		}		
	}  
	//fprintf(my_out_stream,"################################\n");
	fclose(my_in_stream);
	fclose(my_out_stream);
	return 0;
}  
