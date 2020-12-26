/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    
    //if head is NULL or head.next is null 
    if ((head == NULL) || (head->next == NULL)){
        return true;
    }
    
    //1. Take 2 pointers slow and fast 
    struct ListNode* slow = head ;
    struct ListNode* fast = head ;
    
    //2. Find the middle of the linked list 
    while ((fast != NULL) && (fast->next != NULL)){
        slow = slow -> next;
        fast = fast->next ->next;        
    }
    
    //3. code to reverse the linked list - head is slow 
    struct ListNode* prev = NULL;
    struct ListNode* nextNode = NULL;
    struct ListNode* currentNode = slow;
    
    while (currentNode != NULL){
        nextNode = currentNode -> next;
        currentNode->next = prev;
        prev = currentNode;
        currentNode = nextNode;
    }
    
    //4. Move the fast to head of reversed linked list 
    //5. Move the slow to head of original linked list
    fast = prev;
    slow = head;
    
    //6. Now check each value one by one. 
    while (fast != NULL){
        
        if (slow->val == fast->val){
            slow = slow -> next;
            fast = fast -> next;            
        }else{
            //7. The value is not same so return falst
            return false;
        }           
        
    }
    
    //8.if everything is fine - return True    
    return true;
    
    

}
