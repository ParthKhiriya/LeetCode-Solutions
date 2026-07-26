class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int maxm = INT_MIN;

        sort(nums.begin(), nums.end());
        int first = nums[0]*nums[1]*nums[n-1];
        int second = nums[0]*nums[n-2]*nums[n-1];
        int third = nums[n-3]*nums[n-2]*nums[n-1];

        return max(max(first, second), third);
    }
};