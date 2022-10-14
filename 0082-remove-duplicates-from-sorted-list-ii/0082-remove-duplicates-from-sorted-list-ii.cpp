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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next)
            return head;
        
        vector<int>res;
        unordered_map<int,int>m;
        while(head){
            m[head->val]++;
            head=head->next;
        }
        
        for(auto x:m)
        {
            if(x.second==1)
                res.push_back(x.first);
            // cout<<x.first<<" ";
        }
        
        sort(res.begin(),res.end());
        
        
        
        int i=0;
        ListNode* dum=new ListNode(-1),*ans=dum;
        while(i<res.size()){
            dum->next=new ListNode(res[i++]);
            dum=dum->next;
        }
        return ans->next;
    }
};