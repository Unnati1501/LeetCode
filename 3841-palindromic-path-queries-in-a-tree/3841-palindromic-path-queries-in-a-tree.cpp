class Solution {
public:
    int LOG;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth, parent;
    vector<int> prefix;
    vector<int> bit;
    vector<char> chars;
    int timer = 0;
    int n;

    int getMask(char c) {
        return 1 << (c - 'a');
    }

    void updateBIT(int idx, int val) {
        while (idx <= n + 1) {
            bit[idx] ^= val;
            idx += idx & -idx;
        }
    }

    void rangeUpdate(int l, int r, int val) {
        updateBIT(l, val);
        updateBIT(r + 1, val);
    }

    int queryBIT(int idx) {
        int ans = 0;

        while (idx > 0) {
            ans ^= bit[idx];
            idx -= idx & -idx;
        }

        return ans;
    }

    int LCA(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j)) {
                u = up[j][u];
            }
        }

        if (u == v) {
            return u;
        }

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return up[0][u];
    }

    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        this->n = n;
        LOG = 1;

        while ((1 << LOG) <= n) {
            LOG++;
        }

        adj.assign(n, {});
        up.assign(LOG, vector<int>(n, 0));
        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        parent.assign(n, -1);
        prefix.assign(n, 0);
        bit.assign(n + 2, 0);
        chars.assign(s.begin(), s.end());

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Iterative DFS to avoid stack overflow
        vector<pair<int, bool>> st;
        st.push_back({0, false});

        while (!st.empty()) {
            auto [u, exiting] = st.back();
            st.pop_back();

            if (!exiting) {
                tin[u] = ++timer;

                prefix[u] = getMask(chars[u]);

                if (parent[u] != -1) {
                    prefix[u] ^= prefix[parent[u]];
                }

                up[0][u] = (parent[u] == -1 ? u : parent[u]);

                for (int j = 1; j < LOG; j++) {
                    up[j][u] = up[j - 1][up[j - 1][u]];
                }

                st.push_back({u, true});

                for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
                    int v = adj[u][i];

                    if (v == parent[u]) {
                        continue;
                    }

                    parent[v] = u;
                    depth[v] = depth[u] + 1;

                    st.push_back({v, false});
                }
            } else {
                tout[u] = timer;
            }
        }

        for (int u = 0; u < n; u++) {
            rangeUpdate(tin[u], tin[u], prefix[u]);
        }

        vector<bool> ans;

        for (string& q : queries) {
            string type;
            int u;
            char c;

            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                ss >> c;

                int oldMask = getMask(chars[u]);
                int newMask = getMask(c);

                int change = oldMask ^ newMask;

                rangeUpdate(tin[u], tout[u], change);

                chars[u] = c;
            } else {
                int v;
                ss >> v;

                int w = LCA(u, v);

                int maskU = queryBIT(tin[u]);
                int maskV = queryBIT(tin[v]);

                int pathMask = maskU ^ maskV ^ getMask(chars[w]);

                bool possible =
                    (pathMask & (pathMask - 1)) == 0;

                ans.push_back(possible);
            }
        }

        return ans;
    }
};