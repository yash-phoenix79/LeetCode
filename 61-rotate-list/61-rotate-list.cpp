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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next)
            return head;
        
        ListNode* newH,*newT=head,*tail=head;
        int len=0;
        while(tail){
            len++;
            newT=tail;
            tail=tail->next;
        }
        
        newT->next=head;
        
        if(k%=len){
            for(int i=0;i<(len-k);i++)
                newT=newT->next;
        }
        
        newH=newT->next;
        newT->next=NULL;
        
        return newH;
        
    }
};