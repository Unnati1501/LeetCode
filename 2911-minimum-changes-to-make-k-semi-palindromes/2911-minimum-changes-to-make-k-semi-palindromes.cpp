class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                int mini = n;
                for (int d = 1; d < len; d++) {
                    if (len % d != 0)
                        continue;
                    int cnt = 0;
                    for (int x = 0; x < d; x++) {
                        int l = i + x;
                        int r = j - d + 1 + x;
                        while (l < r) {
                            if (s[l] != s[r])
                                cnt++;
                            l += d;
                            r -= d;
                        }
                    }
                    mini = min(mini, cnt);
                }
                cost[i][j] = mini;
            }
        }

        vector<vector<int>> dp(n + 1,vector<int>(k + 1 ,n));
        dp[0][0] = 0;
        for (int p = 1; p <= k; p++) {
            for (int i = 2 * p; i <= n; i++) {
                for (int j = 2 * (p - 1); j < i - 1; j++) {
                    dp[i][p] = min(
                        dp[i][p],
                        dp[j][p - 1] + cost[j][i - 1]
                    );
                }
            }
        }
        return dp[n][k];
    }
};