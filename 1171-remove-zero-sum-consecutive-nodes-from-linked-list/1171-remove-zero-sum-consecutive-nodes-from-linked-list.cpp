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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode*dum=new ListNode(0);
        int sum=0;
        unordered_map<int,ListNode*>m;
        dum->next=head;
        for(ListNode* cur=dum;cur;cur=cur->next)
            m[sum+=cur->val]=cur;
        sum=0;
        for(ListNode* cur=dum;cur;cur=cur->next)
            cur->next=m[sum+=cur->val]->next;
        return dum->next;
    }
};