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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dum=new ListNode(-1);
        ListNode* cur=dum;
        
        while(list1!=NULL&&list2!=NULL){
            if(list1->val<=list2->val){
                cur->next=list1;
                cur=list1;
                list1=list1->next;
            }
            else{
                cur->next=list2;
                cur=list2;
                list2=list2->next;
            }
        }
        
        while(list1!=NULL)
        {
            cur->next=list1;
            cur=list1;
            list1=list1->next;
        }
        
         while(list2!=NULL)
        {
            cur->next=list2;
            cur=list2;
            list2=list2->next;
        }
        return dum->next;
    }
};