#include <stdio.h>
#include <malloc.h>
#include <time.h>

void insertion_sort(int* Arr, int size)
{
	for(int i=0;i<size-1;i++)
	{
		int h = i;
		int j = i+1;
		
		while(Arr[j]<Arr[h] && h>=0)
		{
			Arr[j] ^= Arr[h];
			Arr[h] ^= Arr[j];
			Arr[j] ^= Arr[h];
			h--;
			j--;
		}
	}
	
	
}

int main(int argc, char **argv)
{
	srand(time(NULL));
	
	int size;
	scanf("%d",&size);
	
	int * Arr = (int*) malloc(sizeof(int) * size);
	
	for(int i=0;i<size;i++)
	{
		Arr[i] = rand()%1000 - 400;
		printf("%d ",Arr[i]);	
	}
	printf("\n");
	
	insertion_sort(Arr,size);
	
	for(int i=0;i<size;i++)
	{
		printf("%d ",Arr[i]);
	}
	printf("\n");
	
	return 0;
}

