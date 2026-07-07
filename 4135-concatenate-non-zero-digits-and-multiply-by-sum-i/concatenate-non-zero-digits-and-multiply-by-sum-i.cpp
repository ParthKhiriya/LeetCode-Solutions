class Solution {
public:
    long long sumAndMultiply(int n) {
        long long running = 0;
        int sum = 0;
        int i = 0;

        while(n > 0) {
            int rem = n % 10;
            if(rem == 0) {
                n = n / 10;
                continue;
            }

            running += (rem * pow(10, i));
            sum += rem;
            n = n / 10;
            i++;
        }

        return running*sum;
    }
};