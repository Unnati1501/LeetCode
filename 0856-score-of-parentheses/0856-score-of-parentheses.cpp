class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        int count=0;
        for(char ch : s){
            if(ch=='('){
                st.push(0);
            }
            else{
                int x = st.top();
                st.pop();

                int count = (x == 0) ? 1 : 2 * x;

                st.top() += count;
            }
        }
        return st.top();
    }
};