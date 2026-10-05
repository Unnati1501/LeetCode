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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        
        k=k%n;
        if(k==0){
            return head;
        }

        ListNode* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        tail->next=head;
        ListNode* newtail=head;
        for(int i=0;i<n-k-1;i++){
            newtail=newtail->next;
        }

        ListNode* newhead=newtail->next;
        newtail->next=NULL;

        return newhead;
    }
};