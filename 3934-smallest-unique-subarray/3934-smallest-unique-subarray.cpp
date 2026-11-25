class Solution {
public:
    using ll = long long;

    const ll MOD = 1e9 + 7;
    const ll BASE = 100019;

    bool check(int len, vector<int>& nums) {
        int n = nums.size();

        unordered_map<ll, int> mp;

        ll power = 1;

        for(int i = 0; i < len; i++) {
            power = (power * BASE) % MOD;
        }

        ll hash = 0;

        for(int i = 0; i < len; i++) {
            hash = (hash * BASE + nums[i]) % MOD;
        }

        mp[hash]++;

        for(int i = len; i < n; i++) {

            hash = (hash * BASE) % MOD;

            hash = (hash - (nums[i-len] * power) % MOD + MOD) % MOD;

            hash = (hash + nums[i]) % MOD;

            mp[hash]++;
        }

        for(auto it : mp) {
            if(it.second == 1)
                return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {

        int n = nums.size();

        int low = 1, high = n;
        int ans = n;

        while(low <= high) {

            int mid = low + (high-low)/2;

            if(check(mid, nums)) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }

        return ans;
    }
};