#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}NODE;
NODE* head = NULL;
NODE* currents = NULL;



void printList(){
	NODE* ptr = head;
		while (ptr != NULL){
		
		printf("|%d|->", ptr->data);
		ptr = ptr->next;
	}
	printf("null\n");
}

/**
 *
 * DELETE NODE 
 */

void deleteNode(int data){
	if (head == NULL){
		return;
	}
	if(head->data == data){
		head = head ->next;
	}
	else{
		NODE* ptr = head;
		NODE* prev = ptr;
		while(ptr!= NULL &&ptr->next != NULL){
				// 
				if(ptr->data == data ){
					break;
				}else{
					prev = ptr;
					ptr = ptr->next;
				}
		}
		if( ptr->next == NULL&& ptr->data == data){
			ptr= NULL;
			prev->next = NULL;
			return;
		}
		else {
			prev->next = ptr->next;
			// ptr = NULL;
		}			
	}
}
/**
 *  Will accept an integer value and place it in a link list in sorted order. (low to high)
 * @param data [value you want to add]
 */
void insertNode(int data){
	if(head == NULL){
		NODE *b = (NODE*) malloc(sizeof(NODE));
		b->next = NULL;
		b->data = data; 
		head = b; 

		printf("%d\n", head->data);
		return;
	}
	
	if(data == head->data)  // data already in list
			return;
	if(data<head->data){ //value less than head
		NODE *newFront = (NODE*) malloc(sizeof(NODE));
		newFront->data = data;
		newFront->next = head;
		head = newFront;
		
		return;
	}
		else{ // insert in correct order
			NODE* current = head;
			NODE* prev = current;
			while(current != NULL ){
				if(current->data == data )return;  // value already exists 
				if(data < current->data){
					break;
				}
				prev = current;
				current = current->next;
			} 
				NODE *newNode =(NODE*) malloc(sizeof(NODE));
				newNode->data = data;
				newNode->next = current;
				prev->next = newNode;
				
				return;

		}
}

int main(int argc, char *argv[])
{

	FILE *fp = fopen("text.txt", "r");

	if (fp==NULL)
	{
		printf("error");
		return 0;
	}
	 int number;
	 char letter; 
	 while(!feof(fp)){
	 	
		fscanf(fp, "%c %d\n", &letter, &number);
		// printf("%c\n",letter);
		if(letter == 'i'){
		insertNode(number);
			
		}
		else if(letter == 'd'){
			deleteNode(number);
	}
}
printList();
return 0;
}