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
    
    ListNode* merge(ListNode* left,ListNode* right,int l,int m,int h){
        ListNode* cur1=left,*cur2=right;
        ListNode* dum=new ListNode(-1);
        
        ListNode* cur=dum;
        
       while(cur1&&cur2){
           if(cur1->val<=cur2->val){
               cur->next=new ListNode(cur1->val);
               cur1=cur1->next;
           }
           else{
               cur->next=new ListNode(cur2->val);
               cur2=cur2->next;
           }
           cur=cur->next;
       }
        
        while(cur1){
            cur->next=new ListNode(cur1->val);
            cur1=cur1->next;
            cur=cur->next;
        }
        
        while(cur2){
            cur->next=new ListNode(cur2->val);
            cur2=cur2->next;
            cur=cur->next;
        }
        
        return dum->next;
        
    }
    
    ListNode* mergeSort(ListNode* head,int l,int h){
        if(l<h){
            int m=(l+h)/2;
            ListNode*cur=head,*prev=NULL;
            int t=m;
            m=t-l+1;
            while((m)--){
                prev=cur;
                cur=cur->next;
            }
            prev->next=NULL;
            ListNode* left=mergeSort(head,l,t);
            ListNode* right=mergeSort(cur,t+1,h);
            return merge(left,right,l,t,h);
        }
        else if(l==h)
        return head;
        return NULL;
    }
    
    int getLen(ListNode* head){
        int cur=0;
        while(head){
            cur++;
            head=head->next;
        }
        return cur;
    }
    
    ListNode* sortList(ListNode* head) {
        
        ListNode* cur=head;
        int n=getLen(head);
        
        int l=0,h=n-1;
        
        return mergeSort(head,l,h);
        
        
    }
};