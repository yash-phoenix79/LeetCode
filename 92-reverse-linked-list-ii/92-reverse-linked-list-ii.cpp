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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head||!head->next||left==right)
            return head;
        ListNode*prev=NULL,*cur=head;
        ListNode*tail,*tempH;
        
        while(left>1){
            prev=cur;
            cur=cur->next;
            left--;
            right--;
        }
        
        tempH=prev;
        tail=cur;
        
        ListNode* temp;
        
        while(right>0){
            temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
            right--;
        }
        
        tail->next=cur;
        if(tempH)
            tempH->next=prev;
        else
            head=prev;
        
        return head;
        
    }
};