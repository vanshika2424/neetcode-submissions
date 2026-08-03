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
        ListNode*dummy=new ListNode(-1);
        ListNode*temp=dummy;
        ListNode*i=list1;
        ListNode*j=list2;
        while(i!=NULL && j!=NULL){
            if(i->val<=j->val){
                temp->next=i;
                temp=temp->next;
                i=i->next;
            }
            else{
                temp->next=j;
                temp=temp->next;
                j=j->next;
            }
        }
        while(i!=NULL){
            temp->next=i;
            temp=temp->next;
            i=i->next;
        }
        while(j!=NULL){
            temp->next=j;
            temp=temp->next;
            j=j->next;
        }
        return dummy->next;
        
    }
};
