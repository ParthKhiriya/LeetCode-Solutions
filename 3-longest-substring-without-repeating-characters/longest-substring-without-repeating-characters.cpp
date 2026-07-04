class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<bool> hash(128, false);
        int maxLen = 0;

        int left = 0;
        int right = 0;

        while(right < n) {
            while(hash[s[right]]) {
                hash[s[left]] = false;
                left++;
            }

            hash[s[right]] = true;
            right++;
            maxLen = max(maxLen, right-left);
        }

        return maxLen;
    }
};