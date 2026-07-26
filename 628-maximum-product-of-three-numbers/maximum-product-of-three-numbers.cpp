class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int maxm = INT_MIN;

        sort(nums.begin(), nums.end());
        int first = nums[0]*nums[1]*nums[n-1];
        int second = nums[n-3]*nums[n-2]*nums[n-1];

        return max(first, second);
    }
};