class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int h = n / 2;
        
        int s1 = 0;
        int s2 = 0;
        int q1 = 0;
        int q2 = 0;

        for (int i = 0; i < h; i++) {
            if (num[i] == '?') {
                q1++;
            } else {
                s1 += num[i] - '0';
            }
        }

        for (int i = h; i < n; i++) {
            if (num[i] == '?') {
                q2++;
            } else {
                s2 += num[i] - '0';
            }
        }

        if ((q1 + q2) % 2 != 0) {
            return true;
        }

        if (2 * (s1 - s2) == (q2 - q1) * 9) {
            return false;
        }

        return true;
    }
};