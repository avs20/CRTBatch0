//LEETCODE :https://leetcode.com/problems/merge-two-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    
   
    if ((l1 == NULL) && (l2 == NULL)){
        return NULL;
    }
    if ((l1 == NULL) && (l2 != NULL)){
        return l2;
    }
    if ((l1 != NULL) && (l2 == NULL)){
        return l1;
    }
    
    struct ListNode* head;
    
    struct ListNode* p1; 
    struct ListNode* p2;
    struct ListNode* p1Prev;
    p1 = l1;
    p2 = l2;
    p1Prev = NULL;  
    
    if (p1 -> val <= p2->val)
        head = p1 ;
    else
        head = p2;
    
    
    while (p1 != NULL && p2 != NULL){
        
        if (p1 -> val <= p2 -> val){
            p1Prev = p1;
            p1 = p1 -> next;
        }else{
            if(p1Prev != NULL){
                p1Prev ->next = p2;
            }
            p1Prev = p2;
            p2 = p2->next;
            p1Prev->next = p1;
        }
    }
    
    if (p1 == NULL)
        p1Prev -> next = p2 ;
    
    return head;

}
