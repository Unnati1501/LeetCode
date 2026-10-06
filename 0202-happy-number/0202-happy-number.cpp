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
        int slow=n;
        int fast=n;
        do{
            slow=getSum(slow);
            fast=getSum(getSum(fast));
        }while(slow!=fast);
        return slow==1;
    }
};