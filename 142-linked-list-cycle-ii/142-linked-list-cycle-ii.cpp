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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head,*fast=head,*cur=NULL;
        
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast)
            {
                cur=head;
                break;
            }
        }
        
        if(!cur)
            return NULL;
       
        
        while(cur!=slow){
            cur=cur->next;
            slow=slow->next;
            
        }
        return cur;
    }
};