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
        ListNode* temp=head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        vector<int>ans(v.size(),0);
        stack<int>s;
        for(int i=0;i<v.size();i++){
            while(!s.empty() && v[i]>v[s.top()]){
                ans[s.top()]=v[i];
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};