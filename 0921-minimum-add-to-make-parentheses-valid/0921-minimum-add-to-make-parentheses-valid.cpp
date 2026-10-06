class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        stack<int>st;
        for(char ch:s){
            if(ch=='('){
                st.push(ch);
                count++;
            }
            else if(ch==')' && !st.empty() && st.top()=='('){
                st.pop();
                count--;
            }
            else{
                count++;
            }
        }
        return count;
    }
};