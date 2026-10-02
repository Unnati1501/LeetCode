class Solution {
public:
    vector<string> ans;

    void solve(int n, int open, int close, string str) {
        if (open == n && close == n) {
            ans.push_back(str);
            return;
        }

        if (open < n) {
            solve(n, open + 1, close, str + "(");
        }

        if (close < open) {
            solve(n, open, close + 1, str + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        solve(n, 0, 0, "");
        return ans;
    }
};