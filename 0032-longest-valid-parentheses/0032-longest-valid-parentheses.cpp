class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int count=0;
        int max_count=0;
        st.push(-1);

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    count=i-st.top();
                    max_count=max(max_count,count);
                }
            }   
        }     
        return max_count;
    }
};