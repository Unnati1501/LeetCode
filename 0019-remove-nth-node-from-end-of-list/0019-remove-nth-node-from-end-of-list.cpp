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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev=head;
        ListNode* temp=head->next;
        ListNode* next=head;
        for(int i=0;i<n;i++){
            next=next->next;
        }
        if(next==NULL){
            return temp;
        }
        while(next->next!=NULL){
            prev=prev->next;
            temp=temp->next;
            next=next->next;
        }
        prev->next=temp->next;
        temp->next=NULL;
        return head;
    }
};