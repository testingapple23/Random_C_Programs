#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define squareArraySize 4

void print2DArray(int sizeOfArray, int **ptrArray){
	for (int i = 0; i < sizeOfArray; ++i)
	{
		for (int j = 0; j < sizeOfArray; ++j)
		{
			printf("  %d  ", ptrArray[i][j]);
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

int checkRow(int sizeOfArray, int **ptrArray){
	int magicNumber = 0 , testingForMagicNum =0, count =1;
	for (int i = 0; i < sizeOfArray; ++i)
	{
		for (int j = 0; j < sizeOfArray; ++j)
		{
			if (i==0)
			{
				magicNumber += ptrArray[i][j];
			}
			else{
				testingForMagicNum +=ptrArray[i][j];
			}
		}
		if (i>0)
		{
			if (magicNumber==testingForMagicNum)
			{
				count++;
				testingForMagicNum=0;
			}else return -1;
		}
	}
	if (count == sizeOfArray)
	{
		return 1;
	}
	return -1;
}

int checkDiagonal(int sizeOfArray, int**ptrArray){
	int magicNumber =0 , testingForMagicNum =0;
	for (int i = 0; i < sizeOfArray; ++i)
	{
		for (int j = 0; j < sizeOfArray; ++j)
		{
			if(i == j ){
				magicNumber+= ptrArray[i][j];
			}
			if(i+j ==(sizeOfArray-1)){
				testingForMagicNum+= ptrArray[i][j];
			}
		}
	}
	if (magicNumber == testingForMagicNum)
	{
		return 1;
	}
	return -1;
}

int main(int argc, char *argv[])
{
	static const int magicArray[][squareArraySize]={{16,2,3,13},{5,11,10,8},{9,7,6,12},{4,14,15,1}};
	int (**magicTestArray);
	magicTestArray = (int **)malloc(squareArraySize * sizeof(int*));

	for (int i = 0; i < squareArraySize; ++i)
	{
		magicTestArray[i] = (int*) malloc(squareArraySize* sizeof(int*));

	}


	//used to load random values into array
	int count =1;
	for (int i = 0; i < squareArraySize; ++i)
	{
		for (int j = 0; j < squareArraySize; ++j)
		{
			magicTestArray[i][j]= magicArray[i][j];count++;
		}
	}


 // memcpy(magicTestArray, magicArray, squareArraySize * sizeof(magicArray[squareArraySize][squareArraySize]) );
	int rows =          checkRow(squareArraySize, magicTestArray);
	int x =          checkColumn(squareArraySize, magicTestArray);
	int diagonal = checkDiagonal(squareArraySize, magicTestArray);
	printf("columnCheck:[%d]   rowCheck[%d]   diagonalCheck[%d]\n", x, rows,diagonal);
	print2DArray(squareArraySize, magicTestArray);
	free(magicTestArray);
	if (rows!=-1 && x!=-1 && diagonal !=-1)
	{
		printf("MagicSquareBitch\n");
	}
	else{
		printf("not magic Square\n");
	}
	return 0;
}