/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        stack<vector<int>> s;

        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            vector<int> level;

            while(n--) {
                TreeNode* cur = q.front();
                q.pop();

                level.push_back(cur->val);

                if(cur->left)
                    q.push(cur->left);

                if(cur->right)
                    q.push(cur->right);
            }

            s.push(level);
        }

        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};