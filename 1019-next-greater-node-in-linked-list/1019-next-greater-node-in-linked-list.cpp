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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>v;
        ListNode* curr=head;
        ListNode* fwd;
        while(curr!=NULL){
            fwd=curr->next;
            while(fwd!=NULL){
                if(fwd->val > curr->val){
                    v.push_back(fwd->val);
                    break;
                }
                fwd=fwd->next;
            }
            if(fwd==NULL){
                v.push_back(0);
            }
            curr=curr->next;
        }
        return v;
    }
};