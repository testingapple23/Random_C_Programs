#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define squareArraySize 3

void print2DArray(int sizeOfArray, int **ptrArray){
	for (int i = 0; i < sizeOfArray; ++i)
	{
		for (int j = 0; j < sizeOfArray; ++j)
		{
			printf(" %d ", ptrArray[i][j]);
		}printf("\n");
	}
}
void print(int *arr, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++){
      for (j = 0; j < n; j++){
        printf(" %d ", *((arr+i*n) + j));
    	} printf("\n");
    }
}

/*
	Returns -1  if not magic
 */
int checkColumn(int sizeOfArray, int **ptrArray){
	int magicNumber= 0, testingForMagicNum=0,count=1;
	for (int i = 0; i < sizeOfArray; ++i)
	{
		for (int j = 0; j < sizeOfArray; ++j)
		{
			// magicNumber = 0;
			if (i==0){
				magicNumber += ptrArray[j][i];
			}
			else{
				testingForMagicNum += ptrArray[j][i];
			}
		}
		if (i!=0)
		{
			if (magicNumber == testingForMagicNum)
			{
				count++;
				testingForMagicNum =0;
			}
			else return-1;
		}

	}
	if (count ==sizeOfArray)
	{
		return 1;
	}
	return -1;
}

int main(int argc, char *argv[])
{
	int (**magicTestArray);
	magicTestArray = (int **)malloc(squareArraySize * sizeof(int*));

	for (int i = 0; i < squareArraySize; ++i)
	{
		magicTestArray[i] = (int*) malloc(squareArraySize* sizeof(int*));

	}

	int count =1;
	for (int i = 0; i < squareArraySize; ++i)
	{
		for (int j = 0; j < squareArraySize; ++j)
		{
			magicTestArray[i][j]= count;count++;
		}
	}
	int x = checkColumn(squareArraySize, magicTestArray);
	printf("%d\n", x);
	print2DArray(squareArraySize, magicTestArray);
	free(magicTestArray);
	return 0;
}