class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>map;
        map[0]=1;
        int cnt=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            int previous = sum-k;
            if(map.find(previous)!=map.end()){
                cnt+=map[previous];
            }
            map[sum]++;
        }
        return cnt;
    }
};