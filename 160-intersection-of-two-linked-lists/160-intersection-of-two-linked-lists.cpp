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
        int n1=getLen(headA),n2=getLen(headB);
        
        
        int t;
        if(n1>n2){
         t=n1-n2;
            while(t--)
                headA=headA->next;
        }
           
        else {
            t=n2-n1;
           while(t--)
                headB=headB->next;
        }
        
        while(headA){
            if(headA==headB)
                return headA;
            headA=headA->next;
            headB=headB->next;
        }
            
        return headA;
        
    }
};