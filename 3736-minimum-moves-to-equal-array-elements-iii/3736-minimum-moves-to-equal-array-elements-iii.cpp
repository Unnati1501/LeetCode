class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = 0, sum = 0;
        for (int x : nums) {
            maxi = max(maxi, x);
            sum += x;
        }
        return nums.size() * maxi - sum;
    }
};