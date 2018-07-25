#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}Node;

#define SIZE 10

int hashFunc(int data ){
	return data % SIZE;
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


Node* createNODE(int data){
	
	Node *b = (Node*) malloc(sizeof(Node));
		b->next = NULL;
		b->data = data; 
		return b;
	}
 
int main(int argc, char *argv[]) //a pointer to the first element of the array, which is a pointer to a char
{
	Node* table[SIZE] = {NULL};

	FILE *fp = fopen("text.txt", "r");
	if(fp==NULL)
	{
		printf("error");
		return 0;
	}
	 int number, duplicateCheck;
	 char letter; 
	 while(!feof(fp)){
	 	
		fscanf(fp, "%c %d\n", &letter, &number);
		// printf("%c\n",letter);
		if(letter == 'i'){
			Node* valueInserting = createNODE(number);
			int hashSpot = hashFunc(valueInserting->data); // inserting the value based on the data given (data%SIZE)
			duplicateCheck = search(number, table[hashSpot]); // check if the inputting value has already been put in 

			if (table[hashSpot] == NULL)
			{
				table[hashSpot] = valueInserting;	
			}
			else{
				valueInserting->next = table [ hashSpot];
				table[hashSpot] = valueInserting;
			}
		}
	
}
	printf("%d\n", table[2]->next->data);
return 0;


}