#include<stdio.h>
#include<string.h>
#include<malloc.h>


int* pref_func(char* img, int size)
{
	int *Pi = (int*) malloc(sizeof(int) * size);
	
	Pi[0] = 0;
	
	for(int i = 1, j = 0;i<size;)
	{
		if(img[i] == img[j])
		{
			Pi[i]= j+1;
			j++;
			i++;
		}
		else
		{
			if(j==0)
			{
				Pi[i] = 0;
				i++;
			}
			else
			{
				j = Pi[j-1];
			}
		}
	}
	
	
	return Pi;
	
		
}

int kmp(char*img,char*str,int i_size, int s_size, int*Pi)
{
	int index = -1; //entry index
	
	for(int l=0, k = 0;k < s_size;)
	{
		if(str[k] == img[l])
		{
			k++;
			l++;
			if(l == i_size)
			{
				index = k - l;
				return index;
			}
		}
		else
		{
			if(l == 0)
			{
				k++;
			}
			else
			{
				l = Pi[l-1];
			}
		}
	}
	
	
	return index;
}


int main()
{
	char img[50], str[50];
	fgets(str,50,stdin);
	fgets(img,50,stdin);	
	
	int i_size = strlen(img)-1, s_size = strlen(str)-1;
	
	int*Pi = pref_func(img,i_size);
	
	
	int index = kmp(img,str,i_size,s_size,Pi);
	
	if(index>=0)
	{
		printf("index = %d\n", index);
	}
	else
		printf("no solution\n");



 return 0;
}
