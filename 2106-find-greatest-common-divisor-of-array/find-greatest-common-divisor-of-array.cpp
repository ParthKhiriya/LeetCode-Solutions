class Solution {
public:
    int findGCD(vector<int>& nums) {
        int max_element = INT_MIN;
        int min_element = INT_MAX;

        for(int num: nums) {
            max_element = max(max_element, num);
            min_element = min(min_element, num);
        }

        return gcd(min_element, max_element);
    }
};