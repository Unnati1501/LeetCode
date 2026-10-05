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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp=head;
        ListNode* temp1=head;
        ListNode* temp2=head->next;
        vector<int> v;
        while(temp1){
            v.push_back(temp1->val);
            temp1=temp1->next;
            if(temp1){
                temp1=temp1->next;
            }
        }
        while(temp2){
            v.push_back(temp2->val);
            temp2=temp2->next;
            if(temp2){
                temp2=temp2->next;
            }
        }
        int i=0;
        while(temp){
            temp->val=v[i];
            i++;
            temp=temp->next;
        }
        return head;
    }
};