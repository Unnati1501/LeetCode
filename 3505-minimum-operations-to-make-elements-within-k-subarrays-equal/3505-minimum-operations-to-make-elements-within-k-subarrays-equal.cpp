class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        multiset<int> low, high;

        long long sumLow = 0, sumHigh = 0;

        vector<long long> cost;

        auto balance = [&]() {

            while (low.size() > high.size() + 1) {

                int val = *low.rbegin();

                low.erase(prev(low.end()));
                sumLow -= val;

                high.insert(val);
                sumHigh += val;
            }

            while (low.size() < high.size()) {

                int val = *high.begin();

                high.erase(high.begin());
                sumHigh -= val;

                low.insert(val);
                sumLow += val;
            }
        };

        auto add = [&](int val) {

            if (low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                sumLow += val;
            }
            else {
                high.insert(val);
                sumHigh += val;
            }

            balance();
        };

        auto remove = [&](int val) {

            auto it = low.find(val);

            if (it != low.end()) {
                low.erase(it);
                sumLow -= val;
            }
            else {
                it = high.find(val);
                high.erase(it);
                sumHigh -= val;
            }

            balance();
        };

        for (int i = 0; i < n; i++) {

            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {

                long long median = *low.rbegin();

                long long left =
                    median * low.size() - sumLow;

                long long right =
                    sumHigh - median * high.size();

                cost.push_back(left + right);
            }
        }

        const long long INF = 1e18;

        vector<vector<long long>> dp(
            k + 1,
            vector<long long>(n + 1, INF)
        );

        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        for (int t = 1; t <= k; t++) {

            for (int i = 1; i <= n; i++) {

                dp[t][i] = dp[t][i - 1];

                if (i >= x && dp[t - 1][i - x] != INF) {

                    dp[t][i] = min(
                        dp[t][i],
                        dp[t - 1][i - x] + cost[i - x]
                    );
                }
            }
        }

        return dp[k][n];
    }
};