//function to delete kth node from the end 
void deleteKNodefromLast(int k){
  struct Node * first = head;
  struct Node * second = head; 

  //move second n steps 
  while (k <= 0){
    second = second -> next;
  }

  while (second -> next != NULL){
    first = first -> next;
    second = second -> next;
  }
  
  //now we are before the node to be deleted
  struct Node * tmp = first;
  first = first -> next -> next;
  free(first);

}
