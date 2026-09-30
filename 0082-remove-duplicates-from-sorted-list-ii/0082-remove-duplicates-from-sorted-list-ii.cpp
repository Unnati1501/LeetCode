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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode* prev=NULL;
        ListNode* temp=head;

        while(temp!=NULL){
            if(temp->next!=NULL && temp->val==temp->next->val){
                int val=temp->val;
                while(temp!=NULL && temp->val==val){
                    temp=temp->next;
                }
                if(prev==NULL){
                    head=temp;
                }
                else{
                    prev->next=temp;
                }
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};