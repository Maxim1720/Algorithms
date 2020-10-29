#include <stdio.h>
#include <stdbool.h>


void selection_sort(int *Arr, int size)
{
	int max;
	int max_index;
	bool flag;
	
	while(size>1)
	{
		max = Arr[size-1];
		max_index = size-1;
		flag = false;
		
		
		for(int i=0;i<size;i++)
		{
			if(Arr[i]>max)
			{
				max = Arr[i];
				max_index = i;
				flag = true;
			}
		}	
		
		if(flag)
		{
			Arr[size-1]    ^= Arr[max_index];
			Arr[max_index] ^= Arr[size-1];
			Arr[size-1]    ^= Arr[max_index];
		}
		size--;
	}
}



int main(int argc, char **argv)
{
	int Arr[10] = {0,15,9,1156,4,89,456,159,753,-620};
	
	selection_sort(Arr,10);
	for(int i=0;i<10;i++)
	{
		printf("%d ",Arr[i]);
	}	
	return 0;
}

