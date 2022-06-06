/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    int getLen(ListNode *head){
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        return len;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int len1=getLen(headA),len2=getLen(headB);
        
        if(len1>=len2){
            int t=len1-len2;
            while(t--)
                headA=headA->next;
            
        }
        else{
            int t=len2-len1;
            while(t--)
                headB=headB->next;
        }
        
        while(headA!=NULL){
            if(headA!=NULL&&headA==headB)
                return headA;
            headA=headA->next;
            headB=headB->next;
        }
            return headA;
        
    }
};