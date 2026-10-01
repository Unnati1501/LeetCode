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
    void reorderList(ListNode* head) {
        ListNode* temp=head;
        vector<int>v;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        int l=0;
        int r=v.size()-1;
        while(temp!=NULL){
            temp->val=v[l];
            temp=temp->next;
            if(temp==NULL) break;
            temp->val=v[r];
            temp=temp->next;
            l++;
            r--;
        }
    }
};