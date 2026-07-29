class Solution {
private: 
    long long cappedPermutations(const vector<int>& counts) {
        long long res = 1;
        int n = 0;
        long long CAP = 2000000;

        for(int c: counts) {
            if(c == 0) continue;

            for(int i=1; i<=c; i++) {
                res = res * (n + i) / i;
                
                if(res > CAP) {
                    return CAP + 1;
                }
            }
            n += c;
        }

        return res;
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for(char c: s) {
            freq[c - 'a']++;
        }

        vector<int> half_counts(26, 0);
        string middle = "";
        int half_len = 0;

        for(int i=0; i<26; i++) {
            if(freq[i] % 2 != 0) {
                middle = string(1, (char)(i + 'a'));
            }
            half_counts[i] = freq[i]/2;
            half_len += half_counts[i];
        }

        if(cappedPermutations(half_counts) < k) {
            return "";
        }

        string left_half = "";

        for(int pos = 0; pos < half_len; pos++) {
            for(int i=0; i<26; i++) {
                if(half_counts[i] > 0) {
                    half_counts[i]--;
                    long long perms = cappedPermutations(half_counts);

                    if(perms >= k) {
                        left_half += (char)(i + 'a');
                        break;
                    } else {
                        k -= perms;
                        half_counts[i]++;
                    }
                }
            }
        }

        string right_half = left_half;
        reverse(right_half.begin(), right_half.end());

        return left_half + middle + right_half;
    }
};