//Callatz Cycle Counter
//Alex Crane, 01-7-2012
//Do not use for evil

#include <stdio.h>
#include <time.h>

int number_start;
int number_end;
int the_number;
int cycle_count;
int count;
int record;

float seconds;

main()
{
	time_t time_start;
	time_t time_end;
		
	printf("Enter Start: ");
	scanf("%i",&number_start);
	printf("Enter End: ");
	scanf("%i",&number_end);
	record=0;
	time_start = time(NULL);
	FILE *fp;
	fp = fopen("output.txt","a+");
	fputs("\nNew entry created.\n",fp);
	fprintf(fp,"Finding cycle count from %i to %i.\n",number_start,number_end);		
	
	for(count=number_start; count <= number_end; count++)
	{
		the_number=count;
		printf("%i\n",count);
		while(the_number>1)
		{
			if(the_number % 2 == 0)
			{
				the_number = the_number / 2;
			}
			else
			{
				the_number = (the_number * 3) + 1;
			}
			cycle_count++;
		}
		if(cycle_count>record)
		{
			record=cycle_count;
			//printf("Number %i with %i cycles is finally %i\n",count,cycle_count,the_number);
			fprintf(fp,"Numer %i with %i cycles\n",count,cycle_count);
		}
		cycle_count=0;
	}

	printf("\n");
	time_end = time(NULL);
	seconds=time_end-time_start;
	
	fprintf(fp,"Completed in %f seconds\n",seconds);
	printf("Completed in %f seconds\n",seconds);
	fclose(fp);
	
}
