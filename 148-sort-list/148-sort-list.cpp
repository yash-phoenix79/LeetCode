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
    ListNode* sortList(ListNode* head) {
        
        vector<int>temp;
        ListNode* cur=head;
        while(cur){
            temp.push_back(cur->val);
            cur=cur->next;
        }
        
        sort(begin(temp),end(temp));
        
       ListNode* dum=new ListNode(-1);
        cur=dum;
        
        int i=0;
        while(i<temp.size()){
            cur->next=new ListNode(temp[i++]);
            cur=cur->next;
        }
        
        return dum->next;
        
    }
};