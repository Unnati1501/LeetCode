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

        ListNode* root=reverse_ll(head);
        ListNode* first=root;
        temp=root;

        int i=0;
        while(i<k-1){
            temp=temp->next;
            i++;
        }
        ListNode* second=temp->next;
        temp->next=NULL;

        ListNode* p=reverse_ll(root);
        ListNode* q=reverse_ll(second);
        first->next=q;

        return p;
    }
};