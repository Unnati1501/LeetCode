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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp1=head;
        ListNode* temp2=head->next;
        ListNode* odd1=new ListNode(0);
        ListNode* even1=new ListNode(0);
        ListNode* odd=odd1;
        ListNode* even=even1;
        while(temp1 && temp2){
            odd->next=temp1;
            odd=odd->next;
            temp1=temp1->next;
            odd->next=NULL;
            if(temp1){
                temp1=temp1->next;
            }

            even->next=temp2;
            even=even->next;
            temp2=temp2->next;
            even->next=NULL;
            if(temp2){
                temp2=temp2->next;
            }
        }
        if(temp1){
            odd->next=temp1;
            odd=odd->next;
            odd->next=NULL;
        }
        if(temp2){
            even->next=temp2;
            even=even->next;
            even->next=NULL;
        }
        odd->next=even1->next;
        return odd1->next;
    }
};