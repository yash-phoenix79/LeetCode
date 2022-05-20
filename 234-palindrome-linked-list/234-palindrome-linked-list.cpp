/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverseList(ListNode* head){
        ListNode*prev=NULL,*cur=head,*temp;
        while(cur){
            temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head->next)
            return true;
        ListNode*cur=head,*slow=head,*fast=head,*prev;
        
        while(fast!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
            if(fast==NULL)
                break;
            if(fast->next==NULL){
                slow=slow->next;
                break;
            }
                
        }
        prev->next=NULL;
        slow=reverseList(slow);
        while(slow){
            if(slow->val!=cur->val)
                return false;
            slow=slow->next;
            cur=cur->next;
        }
        
        return true;
        
    }
};