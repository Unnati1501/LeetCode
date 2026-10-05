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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* temp=slow->next;
        slow->next=NULL;
        ListNode* prev=NULL;
        ListNode* fwd=NULL;
        while(temp!=NULL){
            fwd=temp->next;
            temp->next=prev;
            prev=temp;
            temp=fwd;
        }
        temp=head;
        while(temp && prev){
            ListNode* first=temp->next;
            ListNode* second=prev->next;
            temp->next=prev;
            prev->next=first;
            temp=first;
            prev=second;
        }
    }
};