class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> hash(26, 0);
        
        int windowSize = 0;
        int starCount = 0;
        int maxLength = 0;

        int left = 0;
        int right = 0;
        
        while(right < n) {
            hash[s[right] - 'A']++;
            starCount = *max_element(hash.begin(), hash.end());
            windowSize = right-left+1;

            if(windowSize - starCount > k) {
                hash[s[left] - 'A']--;
                left++;
                windowSize = right-left+1;
                starCount = max(starCount, hash[s[right] - 'A']);
            }

            maxLength = max(maxLength, windowSize);
            right++;
        }

        return maxLength;
    }
};