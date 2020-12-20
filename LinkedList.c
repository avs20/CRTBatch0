#include <stdio.h>
#include <stdlib.h>

//structure of node 
struct Node{
    int value;
    struct Node *next;
};

struct Node *head = NULL;

struct Node * insertAtHead(int value){

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
void printAllNodes(){
  //start from head and print all the values 

  if(head == NULL){
    printf("List is empty");
    return;
  }

  struct Node  * temp = head;

  while (temp ->next != NULL){
    printf("%d->", temp->value);
    temp = temp->next;
  }

   printf("%d->NULL\n",temp->value);
}


void insertAfterValue(int afterValue, int value){

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
  temp -> value = value;

  //point the next of currentNode to new node 

  currentNode -> next = temp;



}

//delete head
void deleteHead(){
  if (head == NULL){
    printf("List is empty\n");
    return;    
  }

  // // only head is present in the list
  // if (head->next == NULL){
  //   free(head);
  //   head = NULL;
  //   return;
  // }

  //there are more than 1 node in the list
  struct Node *temp = head;
  head = head -> next;
  free(temp);
}


//delete node which has value
void deleteNodeWithValue( int value){

  //check if list is empty 
  if (head == NULL){
    printf("List is empty");
    return ;
  }

  //check if we need to remove the head 
  if (head -> value == value){
    deleteHead();
    return;
  }

  //now it's not head and not empty 
  //traverse the list to find the node which has value
  struct Node *currentNode, *prevNode;
  currentNode = head->next;
  prevNode = head;
  
  while (currentNode != NULL && currentNode->value != value){
    currentNode = currentNode->next;
    prevNode = prevNode->next;    
  }

  //check if we reached end of list 

  //now we have CR at the correct place and pr at one node before 
  prevNode->next = currentNode->next;
  free(currentNode);

}



int main(void) {

  insertAtHead(4 );  
  insertAtHead(3);
  insertAtHead(2);
  insertAtHead(1);

  printAllNodes();

  insertAfterValue( 3, 5);

  printAllNodes();

  deleteNodeWithValue(5);

  printAllNodes();

  deleteNodeWithValue(1);

  printAllNodes();

  deleteHead();
  deleteHead();

  printAllNodes();
  deleteHead();
  printAllNodes();


  

  
  return 0;
}
