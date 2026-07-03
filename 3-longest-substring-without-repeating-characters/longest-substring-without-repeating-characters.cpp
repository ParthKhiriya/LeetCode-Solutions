class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<int> st;

        int left = 0;
        int right = 0;
        int maxm = 0;

        while(right < n) {
            while(st.contains(s[right])) {
                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);
            right++;
            maxm = max(maxm, right-left);
        }

        return maxm;
    }
};