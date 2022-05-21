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
        if(!head||!head->next)
            return head;
        ListNode* prev=NULL,*cur=head,*temp;
        while(cur){
            temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        return prev;
    }
    
     int getLen(ListNode* head)
    {
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        return len;
    }
    
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head||!head->next)
            return head;
        
        int n=getLen(head);
        if(n<k)
            k%=n;
        else if(k==n)
            return head;
        k=n-k;
        
        ListNode* prev=NULL,*cur=head,*temp,*dum=head;
        
        while(k--)
        {
            temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        
        dum->next=reverse(cur);
        
        return reverse(prev);
        
    }
};