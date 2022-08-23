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
    
    ListNode* reverse(ListNode* head){
        ListNode* cur=head,*prev=NULL,*temp;
        while(cur){
            temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        return prev;
    }
    
    int pairSum(ListNode* head) {
        
        ListNode* cur=head,*slow=head,*fast=head,*prev;
        while(fast!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
            
        }
        
        prev->next=NULL;
        slow=reverse(slow);
        int res=INT_MIN;
        while(head){
            res=max(res,head->val+slow->val);
            slow=slow->next;
            head=head->next;
        }
        return res;
    }
};