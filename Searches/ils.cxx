#include <iostream>
#include <math.h>
#include <time.h>




int index_linear_search(int* Arr, int arr_size, int k)					//индексно-последовательный поиск
{
		
	int integer_part = 0;												//целая часть кв. корня из размера массива данных (главного массива)
	integer_part = (int) sqrtf(arr_size*1.0);							//кв.корень из размера гл.массива будет нашим размером индексного массива
	
	int *index_arr = (int*)malloc(sizeof(int) * integer_part);			//массив индексов
	
	for(int i=0,j=0;i<integer_part;i++,j+=integer_part)
	{
		index_arr[i] = j;
		
	}
	
	
	for(int i=integer_part-1;i>=0;i--)
	{
		if(Arr[index_arr[i]] == k)										/*когда элемент уже находится в таблице индексов*/						
		{
			return index_arr[i];
		}
		
		if(Arr[index_arr[i]] < k)
		{																//_________________________
			
			int end = 0; 												//т.к. интервал между ключевыми полями в главном массиве неравномерный, мы проверяем индекс на наше местоположение в нем.
																		// если это последний промежуток, то мы проходим главный массив от точки входа последнего интервала до конца главного массива
																		// иначе: от точки входа промежутка до конца промежутка
			
			if(i == integer_part-1) 
			{
				end = arr_size;
			}
			else
			{
				end = index_arr[i] + integer_part; 
			}															//______________________________
			
			
			for(int j = index_arr[i]+1; j<=end; j++)
			{
				if(Arr[j] == k)
				{
					return j;
				}
			}
			return -1; 													//если мы проверили весь промежуток, но искомого элемента в нём не оказалось 
																		//- возвращаем неидентифицируемое для индексации значение(отриц.число)
		}
		
	}
	
	return -1;
	
}


int main(int argc, char **argv)
{
	int Arr[10] = {1, 3, 5, 9, 11, 19, 55, 97, 169, 199};
	int search = 0;
	std::cin>>search;
	
	std::cout<<index_linear_search(Arr,10,search)<<std::endl;
	return 0;
}

