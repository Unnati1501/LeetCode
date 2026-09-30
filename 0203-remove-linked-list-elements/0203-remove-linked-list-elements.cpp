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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(head!=NULL && head->val==val){
            temp=temp->next;
            head=temp;
        }
        while(temp!=NULL){
            if(temp->val==val){
                prev->next=temp->next;
                temp->next=NULL;
                temp=prev->next;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};