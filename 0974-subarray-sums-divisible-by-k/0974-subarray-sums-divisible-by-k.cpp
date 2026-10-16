class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        int sum=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            sum += nums[i];
            int val = ((sum%k)+k)%k;
            if(mp.find(val)!=mp.end()){
                cnt += mp[val];
            }
            mp[val]++;
        }
        return cnt;
    }
};