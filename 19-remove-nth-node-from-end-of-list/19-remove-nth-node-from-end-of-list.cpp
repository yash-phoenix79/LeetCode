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
    
    int getLen(ListNode* head){
        int cnt=0;
        while(head){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(!head||!head->next)
            return NULL;
        
        
        int len=getLen(head);
        
        n=len-n+1;
        if(n==1)
            return head->next;
        
        int cnt=1;
        ListNode*prev=NULL,*cur=head;
        
        while(cnt<n){
            prev=cur;
            cur=cur->next;
            cnt++;
        }
        prev->next=cur->next;
        cur->next=NULL;
        return head;
    }
};