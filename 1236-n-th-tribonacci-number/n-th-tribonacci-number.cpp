class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;

        int zero = 0;
        int one = 1;
        int two = 1;

        for(int i=3; i<=n; i++) {
            int result = zero + one + two;
            zero = one;
            one = two;
            two = result;
        }

        return two;
    }
};