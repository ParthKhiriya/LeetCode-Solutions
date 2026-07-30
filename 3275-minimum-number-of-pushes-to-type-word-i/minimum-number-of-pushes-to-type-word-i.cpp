class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        if(n >= 24) {
            return 4*n - 48;
        } else if (n >= 16) {
            return 3*n - 24;
        } else if (n >= 8) {
            return 2*n - 8;
        } else {
            return n;
        }
    }
};