class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        string left_half = "";
        string middle = "";

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                middle = string(1, (char)(i + 'a'));
            }
            
            if (freq[i] > 0) {
                left_half += string(freq[i] / 2, (char)(i + 'a'));
            }
        }

        string right_half = left_half;
        reverse(right_half.begin(), right_half.end());

        return left_half + middle + right_half;
    }
};