//LEETCODE - https://leetcode.com/problems/rotate-list
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    
    
    //1. Find the original tail node 
    //2. Find the length of the list 
    int N = 0;
    struct ListNode* currentNode = head;
    struct ListNode* origTail = NULL;
    
    if ((head == NULL) || (head->next == NULL)){
        return head;
    }
    
    while (currentNode -> next != NULL){
        currentNode = currentNode -> next;
        N += 1;
    }
    
    N += 1;
    origTail = currentNode;   
    
    //3. Set k = k % len
    k = k % N;
    
    //4. find he position of the newTailNode 
    int newTailPos = N - k;    
    
    //5. Get the node of the new Tail node 
    currentNode = head;
    for (int i = 0 ; i < newTailPos - 1; i++) {
        currentNode = currentNode -> next;        
    }
    struct ListNode* newTail = currentNode;
    
    //6. Do our 3 operations
    origTail -> next = head;
    head = newTail->next;
    newTail -> next = NULL;  
    
    return head;
}
