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
    ListNode* reverse_ll(ListNode*head){
        ListNode* temp=head;
        ListNode* fwd=NULL;
        ListNode* prev=NULL;
        while(temp!=NULL){
            fwd=temp->next;
            temp->next=prev;
            prev=temp;
            temp=fwd;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
       head=reverse_ll(head);
       ListNode* curr=head;
       int max1=curr->val;
       while(curr!=NULL && curr->next!=NULL){
        if(curr->next->val<max1){
            curr->next=curr->next->next;
        }
        else{
            curr=curr->next;
            max1=curr->val;;
        }
       }
       head=reverse_ll(head);
       return head;
    }
};