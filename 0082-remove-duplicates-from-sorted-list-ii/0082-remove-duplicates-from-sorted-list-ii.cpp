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
    
    ListNode* dum=new ListNode(0);
    ListNode* prev=dum;
    
    ListNode* deleteDuplicates(ListNode* head) {
        dum->next=head;
        while(head){
            
            if(head->next&&head->next->val==head->val){
                while(head->next&&head->next->val==head->val)
                head=head->next;
                prev->next=head->next;
            }
            else
                prev=prev->next;
            
            head=head->next;
        }
        return dum->next;
    }
};