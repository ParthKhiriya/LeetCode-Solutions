class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st;
        
        for(int i=0; i<n; i++) {
            int curr = temperatures[i];

            while(!st.empty() && curr > temperatures[st.top()]) {
                int lastTop = st.top();
                st.pop();
                answer[lastTop] = i - lastTop;
            }

            st.push(i);
        }

        return answer;
    }
};