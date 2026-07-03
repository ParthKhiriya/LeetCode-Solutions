class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<bool> hash(128, false);

        int left = 0;
        int right = 0;
        int maxm = 0;

        while(right < n) {
            while(hash[s[right]]) {
                hash[s[left]] = false;
                left++;
            }

            hash[s[right]] = true;
            right++;
            maxm = max(maxm, right-left);
        }

        return maxm;
    }
};