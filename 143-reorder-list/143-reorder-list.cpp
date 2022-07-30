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
    
    int findLen(ListNode* head){
        int n=0;
        while(head){
            head=head->next;
            n++;
        }
        return n;
    }
        
    void reorderList(ListNode* head) {
        
        if(!head||!head->next)
            return;
        
        int n=findLen(head);
        
        int t=(n/2)-1;
        ListNode* cur=head;
        while(t--){
            cur=cur->next;
        }
          if(n%2)
              cur=cur->next;
        
        ListNode* cur2=cur->next;
        cur->next=NULL;
        
        ListNode*temp,*prev=NULL;
        
        while(cur2){
            temp=cur2->next;
            cur2->next=prev;
            prev=cur2;
            cur2=temp;
        }
            
        cur=head,cur2=prev;
        ListNode*temp2;
        while(cur2){
            temp=cur->next;
            temp2=cur2->next;
            cur->next=cur2;
            cur2->next=temp;
            cur=temp;
            cur2=temp2;
        }
        
    }
};