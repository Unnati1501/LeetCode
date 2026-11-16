class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string ans;
            int sum = 0, count = 0;
            for (char c : s) {
                sum += c - '0';
                count++;
                if (count == k) {
                    ans += to_string(sum);
                    sum = 0;
                    count = 0;
                }
            }
            if (count > 0) {
                ans += to_string(sum);
            }
            s = ans;
        }
        return s;
    }
};