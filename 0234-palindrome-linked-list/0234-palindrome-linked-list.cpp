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
    bool isPalindrome(ListNode* head) {
        ListNode* curr=head;
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;

        while(curr!=NULL){
            temp->next=new ListNode(curr->val);
            temp=temp->next;
            curr=curr->next;
        }

        temp=dummy->next;
        ListNode* prev=NULL;
        ListNode* fwd=NULL;
        while(temp!=NULL){
            fwd=temp->next;
            temp->next=prev;
            prev=temp;
            temp=fwd;
        }
        dummy=prev;
        temp=dummy;
        curr=head;
        while(temp!=NULL){
            if(temp->val!=curr->val){
                return false;
            }
            temp=temp->next;
            curr=curr->next;
        }
        return true;
    }
};