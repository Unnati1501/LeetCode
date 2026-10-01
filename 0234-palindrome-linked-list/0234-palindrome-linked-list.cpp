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
    ListNode* mid_ll(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* reverse_ll(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* fwd=NULL;
        while(temp!=NULL){
            fwd=temp->next;
            temp->next=prev;
            prev=temp;
            temp=fwd;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        ListNode* root=mid_ll(head);
        ListNode* curr=reverse_ll(root->next);

        while(curr!=NULL){
            if(temp->val!=curr->val){
                return false;
            }
            temp=temp->next;
            curr=curr->next;
        }
        return true;
    }
};