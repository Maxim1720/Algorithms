#include <stdio.h>


int binary_search(int *Arr,int arr_size,int k)
{

	int beg = 0, end = arr_size-1;
	
	while(beg<=end)
	{
		int mid = beg + (end - beg)/2;

		if(Arr[mid] == k)
		{
			return mid;
		}
		else
		{
			if(k > Arr[mid])
			{
				beg = mid+1;
			}
			else
			{
				end = mid-1;
			}
		}
	}
	return -1;

}




int main(int argc, char const *argv[])
{
	int Arr[10] = {1,5,150,300,976, 10456, 105050, 787878, 989898,100000000};
	
	int a;
	scanf("%d",&a);
	a = binary_search(Arr,10,a);
	if(a>0)
		printf("%d\n",a);
	else
		printf("No Solution\n");

	return 0;
}