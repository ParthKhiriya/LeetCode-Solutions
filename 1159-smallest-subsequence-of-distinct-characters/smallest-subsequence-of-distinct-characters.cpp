class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int> lastIndex(26, 0);
        for(int i=0; i<n; i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        string st = "";
        vector<bool> inStack(26, false);

        for(int i=0; i<n; i++) {
            char c = s[i];

            if(inStack[c - 'a']) {
                continue;
            }

            while(!st.empty() && st.back() > c && lastIndex[st.back() - 'a'] > i) {
                inStack[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            inStack[c - 'a'] = true;
        }

        return st;
    }
};