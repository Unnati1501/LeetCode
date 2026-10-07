class Solution {
public:
    vector<string> ans;

    void dfs(string s, int start, int left, int right) {

        if (left == 0 && right == 0) {
            if (isValid(s)) {
                ans.push_back(s);
            }
            return;
        }

        for (int i = start; i < s.length(); i++) {

            if (i > start && s[i] == s[i - 1])
                continue;

            if (s[i] == '(' && left > 0) {
                string temp = s.substr(0, i) + s.substr(i + 1);

                dfs(temp, i, left - 1, right);
            }

            if (s[i] == ')' && right > 0) {
                string temp = s.substr(0, i) + s.substr(i + 1);

                dfs(temp, i, left, right - 1);
            }
        }
    }

    bool isValid(string s) {
        int count = 0;

        for (char ch : s) {

            if (ch == '(') {
                count++;
            }
            else if (ch == ')') {
                count--;

                if (count < 0)
                    return false;
            }
        }

        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {

        int left = 0;
        int right = 0;

        for (char ch : s) {

            if (ch == '(') {
                left++;
            }
            else if (ch == ')') {

                if (left > 0)
                    left--;
                else
                    right++;
            }
        }

        dfs(s, 0, left, right);

        return ans;
    }
};