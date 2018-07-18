#include <stdio.h>
#include <stdlib.h>


int* sort(int arraySize, int* theArray){
	if(arraySize == 0 || arraySize == 1){
		return theArray;
	}
	else{
		for (int i = 0; i < arraySize; ++i)
		{
			
			for (int j = 1; j < arraySize; ++j)
			{
				if (theArray[j]<theArray[i])
				{

					int swap = theArray[i];
					theArray[i] = theArray[j];
					theArray[j] = swap;
				}
			}
		}
		for (int i = 0; i < 6; ++i)
			{
				printf("%d, ", theArray[i]);
			}

		return theArray;
	}
}
int main(int argc, char *argv[]){

	int a[] = {5, 54, 2, 1, 555, 334};
	int* ca = sort(6 , a);
	for (int i = 0; i < 5; ++i)
	{
		// printf("%d", ca[i]);
	}
return 0;

}