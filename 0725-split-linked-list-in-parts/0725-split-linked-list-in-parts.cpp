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
        int n=0;
        while(head){
            n++;
            head=head->next;
        }
        return n;
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        

        int len=getLen(head);
        
        vector<int>part(k,len/k);
        int t=len%k;
        
        // cout<<t<<endl;
        
        int i=0;
        while(t--){
            part[i++]++;
        }
        
//         for(int i=0;i<k;i++)
//             cout<<part[i]<<' ';
        
        vector<ListNode*>res(k);
        
        ListNode* cur=head,*prev;
        for(int i=0;i<k&&len>0;i++){
            res[i]=cur;
            while(part[i]--){
                prev=cur;
                cur=cur->next;
                len--;
            }
            prev->next=NULL;
            
        }
        return res;
    }
};