class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        vector<int> ans(n, 0);
        vector<int> st[26];
        function<void(int,int)> dfs = [&](int node, int par) {
            ans[node] = 1;
            int idx = s[node] - 'a';
            st[idx].push_back(node);
            for(int child : adj[node]) {
                dfs(child, node);
            }
            int newParent = par;
            if(st[idx].size() > 1) {
                newParent = st[idx][st[idx].size() - 2];
            }
            if(newParent != -1) {
                ans[newParent] += ans[node];
            }
            st[idx].pop_back();
        };
        dfs(0, -1);
        return ans;
    }
};