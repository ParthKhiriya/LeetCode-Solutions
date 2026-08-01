class Solution {
private: 
    int solve(int left, int right, vector<int>& nums, vector<vector<int>>& memo) {
        if(left == right) {
            return nums[left];
        }

        if(memo[left][right] != -1) {
            return memo[left][right];
        }

        int pick_left = nums[left] - solve(left + 1, right, nums, memo);
        int pick_right = nums[right] - solve(left, right - 1, nums, memo);
        
        return memo[left][right] = max(pick_left, pick_right);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return solve(0, n-1, nums, memo) >= 0;
    }
};