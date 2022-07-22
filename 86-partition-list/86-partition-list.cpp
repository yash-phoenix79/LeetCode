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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dum1=new ListNode(-1),*dum2=new ListNode(-1);
        ListNode*tHead=dum1;
        ListNode*tTail=dum2;
        
        ListNode* cur=head,*temp;
        
        while(cur){
          temp=cur->next;
            if(cur->val<x)
            {
                dum1->next=cur;
                dum1=cur;
                dum1->next=NULL;
               
            }
            else{
                dum2->next=cur;
                dum2=cur;
                dum2->next=NULL;
            }
            cur=temp;
        }
        
        dum1->next=tTail->next;
        
        return tHead->next;
        
    }
};