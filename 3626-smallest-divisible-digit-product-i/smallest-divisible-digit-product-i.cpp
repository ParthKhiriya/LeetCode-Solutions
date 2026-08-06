class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n; i<INT_MAX; i++) {
            int num = i;
            int mult = 1;
            while(num > 0) {
                int digit = num % 10;
                mult *= digit;
                num = num / 10;
            }
            if(mult % t == 0) {
                return i;
            }
        }

        return n;
    }
};