#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int **ptr, int OneDimensionSize , int TwoDimensionSize){
	for (int i = 0; i < OneDimensionSize; ++i)
	{
		for (int j = 0; j < TwoDimensionSize; ++j)
		{
			// printf(" %d ", *((ptr+i*TwoDimensionSize)+j) );
			printf(" %d ", ptr[i][j]);
		}printf("\n");
			}
}

int **raiseArrayToPower(int exponent, int** originalArray, int**duplicateArray, int** result ,int sizeOfRowAndColumn){
		// int** duplicate2 = malloc(sizeof(originalArray));
		for (int i = 0; i < sizeOfRowAndColumn; i++)
		{
			for (int j = 0; j < sizeOfRowAndColumn; j++)
			{
				for (int k = 0; k < sizeOfRowAndColumn; k++)
				{
					printf("[%d][%d] %d [%d][%d] %d \t", i,k, originalArray[i][k] , k,j ,originalArray[k][j]);
                	duplicateArray[i][j] +=  originalArray[i][k] * originalArray[k][j];
				}
				printf("\n");
			}
		}
			for (int i = 0; i < sizeOfRowAndColumn; i++)
		{
			for (int j = 0; j < sizeOfRowAndColumn; j++)
			{
				for (int k = 0; k < sizeOfRowAndColumn; k++)
				{
					printf("[%d][%d] %d [%d][%d] %d \t", i,k, originalArray[i][k] , k,j ,originalArray[k][j]);
                	result[i][j] +=  duplicateArray[i][k] * originalArray[k][j];
				}
				printf("\n");
			}
		}

	return result;
}



void print(int *arr, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
        printf(" %d ", *((arr+i*n) + j));
}

int main(int argc, char *argv[])
{
	int matrixExpo[][3] = {{1,2,3},
						   {4,5,6},
						   {7,8,9}};
		
	// for (int i = 0; i < 3; ++i)
	// {
	// 	for (int j = 0; j < 3; ++j)
	// 	{
	// 		printf(" %d ", matrixExpo[i][j]);
	// 	}printf("\n");
	// }
	// 
	// 
	int **ptr2DArrayBuffer, **duplicate, **result;
	ptr2DArrayBuffer = (int **)malloc(3 * sizeof(int*));
	duplicate = (int **)malloc(3 * sizeof(int*));
	result = (int **)malloc(3 * sizeof(int*));

	for (int i = 0; i < 3; ++i)	{
	 ptr2DArrayBuffer[i] =(int *)malloc(3 * sizeof(int));
		duplicate[i] =(int *)malloc(3 * sizeof(int));
		result[i] =      (int *)malloc(3 * sizeof(int));
	}

	int count =1;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			ptr2DArrayBuffer[i][j]=count;
			duplicate[i][j]=0;
			result[i][j]=0;
			count++;
		}
	}
	
	// duplicate = malloc(sizeof(ptr2DArrayBuffer));
	// memcpy(duplicate,ptr2DArrayBuffer, sizeof(int)*9);
// int (*ptr)[3][3] = &ptr2DArrayBuffer;
// 
// 
	printArray(duplicate, 3,3);

	raiseArrayToPower(1,ptr2DArrayBuffer,duplicate,result,3);
	printArray(duplicate, 3,3);
	printArray(result,3,3);

	free(result);
	free(duplicate);
	free(ptr2DArrayBuffer); 
	return 0;
}