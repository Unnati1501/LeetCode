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
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        ListNode* head;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        
        if(temp2->val<temp1->val){
            head=temp2;
            temp2=temp2->next;
        }
        else{
            head=temp1;
            temp1=temp1->next;
        }

        ListNode* prev=head;

        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<=temp2->val){
                prev->next=temp1;
                temp1=temp1->next;
            }
            else{
                prev->next=temp2;
                temp2=temp2->next;
            }
            prev=prev->next;
        }
        if(temp1!=NULL){
            prev->next=temp1;
        }
        else{
            prev->next=temp2;
        }
        return head;
    }
};