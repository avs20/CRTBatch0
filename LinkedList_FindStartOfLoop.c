//function to find start of loop in a linked list. 
struct Node * getStartOfLoop(){
  if (head == NULL){
    printf("The list is empty\n");
    return NULL;
  }

  //create 2 pointers
  struct Node * first;
  struct Node * second;

  //move the first pointer 1 step
  first = head -> next;
  //move the second pointer 2 steps
  second = head -> next -> next;

  //now check until the both are same
  //move first by 1 step
  //move second by 2 step
  while (first != second ){
      first = first -> next;
      second = second -> next -> next ;
  }

  //now both are at same position 
  //move the first to head 
  first = head;
  
  //now move both at 1 speed until they are same again 
  while (first != second){
    first = first -> next;
    second = second -> next;
  }

  //now they are at loop start 
  return first;


}
