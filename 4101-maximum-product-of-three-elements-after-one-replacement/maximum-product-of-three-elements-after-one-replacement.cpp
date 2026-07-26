class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long max1 = INT_MIN, max2 = INT_MIN;
        long long min1 = INT_MAX, min2 = INT_MAX;

        for(int num: nums) {
            if(num > max1) {
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max2 = num;
            }

            if(num < min1) {
                min2 = min1;
                min1 = num;
            } else if (num < min2) {
                min2 = num;
            }
        }

        long long first = max1 * max2 * 100000;
        long long second = max1 * min1 * -100000;
        long long third = min1 * min2 * 100000;

        return max(max(first, second), third); 
    }
};