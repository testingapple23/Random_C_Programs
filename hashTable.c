#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}Node;

#define SIZE 10

int hashFunc(int data ){
	return data% SIZE;
}

int search(int lookingFOR, Node* head){  
	if(head == NULL){
		return -1; // not in list
	}
	Node* current = head;
	while(current != NULL){
		if (current-> data == lookingFOR)
		{
			return 1;
		}
		current = current->next;
	}
	return -1; // not found 
}


void insertNODE(int data, Node* theArray){
	int key = hashFunc(data);
	if (theArray[key]  NULL)
	{
		
	}
}
int main(int argc, char *argv[])
{
	Node (*theArray)[SIZE];
	for (int i = 0; i < SIZE; ++i)
	{
		theArray[i]=NULL;
	}
	return 0;
}