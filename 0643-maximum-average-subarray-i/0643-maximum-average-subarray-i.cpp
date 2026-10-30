class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        double maxSum=INT_MIN;
        int n = nums.size();
        int s=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(i>=k-1){
                maxSum=max(maxSum,sum);
                sum -= nums[s];
                s++;
            }
        }
        return maxSum/k;
    }
};