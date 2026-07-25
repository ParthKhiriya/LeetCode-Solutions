class Solution {
private: 
    int helper(vector<int>& nums, int start, int end) {
        int second = nums[start];
        int first = max(nums[start], nums[start + 1]);

        for(int i = start + 2; i <= end; i++) {
            int result = max(second + nums[i], first);
            second = first;
            first = result;
        }

        return first;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        int withZero = helper(nums, 0, n-2);
        int withoutZero = helper(nums, 1, n-1);

        return max(withZero, withoutZero);
    }
};