#include <stdio.h>
#include <stdlib.h>

//structure of node 
struct Node{
    int value;
    struct Node *next;
};


struct Node * insertAtHead(int value, struct Node *head){

    struct Node *temp;

    //allocate memory 
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->value = value;

    //point the next of this node to where head is pointing 
    temp->next = head;

    //point the head to this node
    head = temp;

    return head;

}

//Printing all the nodes in linked list 
void printAllNodes(struct Node *head){
  //start from head and print all the values 

  if(head == NULL){
    printf("List is empty");
  }

  struct Node  * temp = head;

  while (temp ->next != NULL){
    printf("%d->", temp->value);
    temp = temp->next;
  }

   printf("%d->NULL",temp->value);
}


void insertAfterValue(struct Node * head, int afterValue, int value){

  struct Node *temp, *currentNode;

  currentNode = head;
    // printf("%d", head->value);


  //travel till the node after which value to be insertAtHead
  while(currentNode != NULL && currentNode->value != afterValue ){
    currentNode = currentNode -> next;
  }


  //check if current node is not null 
  if (currentNode == NULL ){
    printf("The value does not exist!");
    return ;
  }
  

  //create the new node 
  temp = (struct Node *)malloc(sizeof(struct Node));

  //point the new node to the next of currentNode 
  temp -> next = currentNode -> next;

  //point the next of currentNode to new node 

  currentNode -> next = temp;



}



int main(void) {

  struct Node* head = NULL;
  head = insertAtHead(4, head);  
  head = insertAtHead(3, head);
  head = insertAtHead(2, head);
  head = insertAtHead(1, head);

  printAllNodes(head);

  insertAfterValue(head, 3, 5);

  printAllNodes(head);

  
  return 0;
}
