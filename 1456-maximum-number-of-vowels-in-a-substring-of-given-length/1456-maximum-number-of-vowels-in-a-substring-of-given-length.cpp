class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.length();
        int cnt=0;
        int maxCnt=0;
        int j=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                    cnt++;
            }
            if(i>=k-1){
                maxCnt=max(maxCnt,cnt);
                if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u'){
                    cnt--;
                }
                j++;
            }
        }
        return maxCnt;
    }
};