class Solution {
public:
    int getSum(int n){
        int sum=0;
        int a=0;
        while(n>0){
            a=n%10;
            sum+=a*a;
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int sum=n;
        unordered_map<int,int>freq;
        while(sum!=1){
            sum=getSum(sum);
            if(freq.count(sum)==1){
                return false;
            }
            freq[sum]+=1;
        }
        return true;
    }
};