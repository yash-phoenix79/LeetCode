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
    
    ListNode*l;
    bool stop=false;
    
    void reverse(ListNode* r,int left,int right){
        if(right==1){
           
              return;
        }
          
     
        r=r->next;
        
        if(left>1){
            l=l->next;
        }
        
        reverse(r,left-1,right-1);
        
        if(l==r||r->next==l)
            stop=true;
        if(!stop){
            swap(l->val,r->val);
            l=l->next;
        }
        
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        l=head;
        ListNode* r=head;
        reverse(r,left,right);
        return head;
    }
};