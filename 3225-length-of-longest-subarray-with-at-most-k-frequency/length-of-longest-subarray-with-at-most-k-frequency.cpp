class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        int left = 0;
        int right = 0;
        int count = 0;

        while(right < n) {
            mpp[nums[right]]++;
            if(mpp[nums[right]] > k) {
                count = max(count, right-left);
                while(left < right && mpp[nums[right]] > k) {
                    mpp[nums[left]]--;
                    left++;
                }
            }
            right++;
            count = max(count, right-left);
        }

        return count;
    }
};