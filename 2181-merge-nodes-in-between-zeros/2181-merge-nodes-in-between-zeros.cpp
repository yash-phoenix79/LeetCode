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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode*dum= new ListNode(-1),*hol;
        
        hol=dum;
        
        ListNode* cur=head;
        cur=cur->next;
        while(cur){
            int sum=0;
            while(cur->val!=0){
                sum+=cur->val;
                cur=cur->next;
            }
           // cout<<sum<<endl;
           dum->next=new ListNode(sum);
            dum=dum->next;
             cur=cur->next;
        }
        
        return hol->next;
        
    }
};