class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int sum=0;
        int cnt=0;
        int j=0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(i>=k-1){
                int avg = sum/k;
                if(avg >= threshold){
                    cnt++;
                }
                sum -= arr[j];
                j++;
            }
        }
        return cnt;
    }
};