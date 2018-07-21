#include <stdio.h>
#include <stdlib.h>


void printArray(int arraySize, int* theArray){
				for (int i = 0; i < arraySize; ++i)
			{
				printf("%d, ", theArray[i]);
			}
}

int binarySeach(int arraySize, int* theArray, int key){
	if (arraySize == 0)
	{
		return -1;
	}
	if (arraySize == 1 && theArray[0]== key)
	{
		return 0; 
	}

	else{

		int lower = 0;
		int max = arraySize-1;
		int middle = (lower+max)/2;
	
		while(lower<=max){
		if (theArray[middle] == key)
		{

			return middle; // value found, so return middle index
		}
		else if (theArray[middle] > key){
			max= middle-1;
			middle = max/2;
		}
		else if(theArray[middle]  < key){
			lower = middle+1;
			middle = (max + lower ) /2 ; 
		}
	}
}
	return -1; // not found
}

int* sort(int arraySize, int* theArray){
	if(arraySize == 0 || arraySize == 1){
		return theArray;
	}
	else{
		for (int i = 0; i < arraySize; ++i)
		{
			
			for (int j = i+1; j < arraySize; ++j)
			{
				if (theArray[j]<theArray[i])
				{
					
					int swap = theArray[i];
					theArray[i] = theArray[j];
					theArray[j] = swap;
					
				}
			}
		}
		
		return theArray;
	}
}
int main(int argc, char *argv[]){

	int a[] = {5, 4};
	int arraySIZE =2 ;
	int* ca = sort(arraySIZE , a);
	printArray(arraySIZE,ca);
	
printf("\n");
	int x = binarySeach(arraySIZE , a , 5);
	printf("%d\n", x);
return 0;

}