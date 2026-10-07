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
    ListNode* partition(ListNode* head, int x) {
      ListNode* temp=head;
      ListNode* temp1=NULL;
      ListNode* temp2=NULL;
      ListNode* head1=NULL;
      ListNode* head2=NULL;
      while(temp!=NULL){
        ListNode* next=temp->next;
        if(temp->val<x){
            if(temp1==NULL){
                temp1=temp;
                head1=temp1;
            }
            else{
                temp1->next=temp;
                temp1=temp1->next;
            }
        }
        else{
            if(temp2==NULL){
                temp2=temp;
                head2=temp2;
            }
            else{
                temp2->next=temp;
                temp2=temp2->next;
            }
        }
        temp=next;
      }
      if(temp2!=NULL){
        temp2->next=NULL;
      }  
      if(head1!=NULL){
        temp1->next=head2;
        return head1;
      }
      return head2; 
    }
};