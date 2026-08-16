class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;

        int left = 0;
        int maxm = 0;

        for(int right=0; right<n; right++) {
            mpp[s[right]]++;

            while(mpp[s[right]] > 2) {
                mpp[s[left]]--;
                left++;
            }

            maxm = max(maxm, right-left+1);
        }

        return maxm;
    }
};