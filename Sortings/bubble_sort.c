#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int* Arr, int size)
{
	bool flag = false;
	
	while(!flag)
	{
		flag = true;
		for(int i=1;i<size;i++)
		{
			if(Arr[i-1]>Arr[i])
			{
				Arr[i]  ^= Arr[i-1];
				Arr[i-1]^= Arr[i];
				Arr[i]  ^= Arr[i-1];
				flag = false;
			}
		}
		
	}
}

int main(int argc, char **argv)
{
	int Arr[10] = {456, -59, 879, 99, 2, 66, 4, 71, 369, 10};
	bubble_sort(Arr,10);
	for(int i=0;i<10;i++)
	{
		printf("%d ",Arr[i]);
	}
	return 0;
}

