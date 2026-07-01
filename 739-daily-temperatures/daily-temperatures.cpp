class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;

        for(int i=0; i<n; i++) {
            int current = temperatures[i];

            while(!st.empty() && current > temperatures[st.top()]) {
                int prevDay = st.top();
                st.pop();
                ans[prevDay] = i - prevDay;
            }
            st.push(i);
        }

        return ans;
    }
};