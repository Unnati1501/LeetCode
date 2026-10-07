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
    ListNode* reverse_ll(ListNode* head,int k){
        ListNode* prev=NULL;
        ListNode* temp=head;
        ListNode* fwd=NULL;
        int n=0;
        while(n<k){
            fwd=temp->next;
            temp->next=prev;
            prev=temp;
            temp=fwd;
            n++;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        int n=0;

        while(temp!=NULL){
            n++;
            temp=temp->next;
        }

        int i=n/k;

        temp=head;
        ListNode* prev= NULL;

        while(i>0){

            ListNode* groupStart = temp;

            int j=0;

            while(j<k){
                temp=temp->next;
                j++;
            }

            ListNode* next = temp;

            ListNode* newHead = reverse_ll(groupStart, k);

            if(prev != NULL) {
                prev->next = newHead;
            }
            else {
                head = newHead;
            }

            groupStart->next = next;

            prev = groupStart;

            i--;
        }
        return head;
    }
};