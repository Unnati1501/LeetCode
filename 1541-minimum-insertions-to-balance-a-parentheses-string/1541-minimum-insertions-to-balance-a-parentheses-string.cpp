class Solution {
public:
    int minInsertions(string s) {
        stack<char>st;
        int cnt=0;
        int n=s.length();
        for(int i=0;i<n;i){
            if(s[i]=='('){
                st.push(s[i]);
                i++;
            }
            else if(st.empty() && s[i]==')'){
                if(s[i+1]==')'){
                    cnt++;
                    i+=2;
                }
                else{
                    cnt+=2;
                    i++;
                }
            }
            else{
                if(s[i]==')' && i+1<n && s[i+1]==')'){
                    st.pop();
                    i+=2;
                }
                else{
                    st.pop();
                    cnt++;
                    i++;
                }
            }
        }
        if(!st.empty()){
            int i=st.size();
            while(i>0){
                cnt+=2;
                i--;
            }
        }
        return cnt;
    }
};