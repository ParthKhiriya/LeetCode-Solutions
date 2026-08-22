class Solution {
public:
    bool checkDivisibility(int n) {
        int copy = n;
        int sum = 0;
        int product = 1;

        while(n != 0) {
            int digit = n % 10;
            sum += digit;
            product *= digit;
            n = n / 10;
        } 

        return (copy % (sum + product) == 0) ? true : false;
    }
};