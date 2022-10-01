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
        ListNode* head=dum;
        
        while(list1&&list2){
            if(list1->val<=list2->val){
                dum->next=list1;
               list1=list1->next;
            }
            else{
                dum->next=list2;
                list2=list2->next;
            }
             dum=dum->next;
        }
        
        while(list1){
            dum->next=list1;
               list1=list1->next;
             dum=dum->next;
        }
        
        while(list2){
             dum->next=list2;
               list2=list2->next;
             dum=dum->next;
        }
        return head->next;
    }
};