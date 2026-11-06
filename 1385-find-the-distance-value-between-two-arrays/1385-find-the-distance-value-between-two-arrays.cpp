class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for(int i:arr1){
            bool valid = true;
            for(int j:arr2){
                if(abs(i-j)<=d){
                    valid=false;
                    break;
                }
            }
            if(valid){
                ans++;
            }
        }
        return ans;
    }
};