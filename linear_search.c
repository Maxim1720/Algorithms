#include <stdio.h>


int linear_search(int *Arr, int arr_size, int k)
{
	for(int i=0;i<arr_size;i++)
		if(Arr[i] == k)
			return i;

	return -1;

}


int main(int argc, char const *argv[])
{
	int Arr[10] = {0, 99, 44, 6, 13, 812, 54, 3, 7, -16};

	int a;
	scanf("%d",&a);
	a = linear_search(Arr,10,a);

	if(a>0)
		printf("%d\n", a);
	else
		printf("No solution\n");
	return 0;
}