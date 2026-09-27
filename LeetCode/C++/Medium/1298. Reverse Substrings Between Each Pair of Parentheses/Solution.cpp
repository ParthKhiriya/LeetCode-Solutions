class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        string current = "";
        stack<string> st;

        for(char c: s) {
            if(c == '(') {
                st.push(current);
                current = "";
            } else if (c == ')') {
                reverse(current.begin(), current.end());

                if(!st.empty()) {
                    current = st.top() + current;
                    st.pop();
                }
            } else {
                current += c;
            }
        }

        return current;
    }
};