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
    
    ListNode* findRev(ListNode* head,int i,int k,int n){
        if(i>=n)
            return head;
        
        ListNode* prev=NULL,*dum=head,*cur=head,*temp=head->next;
        
        int t=k;
        while(t--){
            temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
            
        dum->next=findRev(cur,i+1,k,n);
        return prev;
    }
    
    int getLen(ListNode* head){
        int len=0;
        while(head){
             head=head->next;
            len++;
        }
           return len;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        
        
        int len=getLen(head);
        int n=len/k;
        
        return findRev(head,0,k,n);
        
    }
};