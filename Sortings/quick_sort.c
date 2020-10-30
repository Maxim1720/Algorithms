#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


int partition(int Arr[], int low, int high)
{
	int i = (low-1);
	int pivot = Arr[high];
	
	for(int j=low;j<high;j++)
	{
		if(Arr[j]<pivot)
		{
			i++;
			swap(&Arr[i], &Arr[j]);
			
		}
		
		
	}
	swap(&Arr[i+1], &Arr[high]);
	return (i+1);
}


void quick_sort(int Arr[], int low, int high)
{
	
	
	
	if(low<high)
	{
		int pivot = partition(Arr,low,high);	   						//элемент, который будет выступать в качестве разделителя/опорного элемента. Справа от него - элементы больше, слева - меньше. 

		quick_sort(Arr,low,pivot-1);
		quick_sort(Arr,pivot+1,high);
		
	}
	
	
}





int main(int argc, char **argv)
{
	srand( (unsigned int) time(NULL));
	int size;
	scanf("%d",&size);
	
	int* Arr = (int*)malloc(sizeof(int)*size);
	
	for(int i=0;i<size;i++)
	{
		Arr[i] = rand()%120 - 50;
		printf("%d ",Arr[i]);
	}
	printf("\n");
	
	
	quick_sort(Arr,0,size-1);
	
	for(int i=0;i<size;i++)
	{
		printf("%d ",Arr[i]);
	}
	printf("\n");
	
	return 0;
}

