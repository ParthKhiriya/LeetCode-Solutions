class Solution {
private: 
    int houseRobber(vector<int>& nums, int start, int end) {
        int one = nums[start];
        int two = max(nums[start], nums[start+1]);

        for(int i=start+2; i<=end; i++) {
            int result = max(two, one + nums[i]);
            one = two;
            two = result;
        }

        return two;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        int no_zero = houseRobber(nums, 0, n-2);
        int yes_zero = houseRobber(nums, 1, n-1);

        return max(no_zero, yes_zero);
    }
};