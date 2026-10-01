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
        ListNode* temp=head;
        ListNode* prev=NULL;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        temp=head;
        if(count-n==0){
            head=head->next;
            temp=temp->next;
            return head;
        }
        for(int i=0;i<count-n;i++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        temp->next=NULL;
        return head;
    }
};