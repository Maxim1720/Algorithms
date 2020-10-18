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
