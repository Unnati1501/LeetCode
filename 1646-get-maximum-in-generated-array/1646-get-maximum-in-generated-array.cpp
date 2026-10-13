class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0) return 0;
        vector<int>v(n+1,0);
        v[1]=1;
        int maxi=max(v[0],v[1]);
        for(int i=2;i<=n;i++){
            if(i%2==0){     
                v[i]=v[i/2];
            }
            else{
                v[i]=v[i/2]+v[i/2+1];
            }
            maxi=max(maxi,v[i]);
        }
        return maxi;
    }
};