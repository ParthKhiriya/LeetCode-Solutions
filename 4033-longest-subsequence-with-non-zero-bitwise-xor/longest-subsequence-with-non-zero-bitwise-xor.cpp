class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        bool flag = false;
        int x = 0;

        for(int i=0; i<n; i++) {
            x ^= nums[i];
            if(nums[i] != 0) flag = true;
        }

        if(x != 0) return n;
        if(flag == false) return 0;

        return n-1;
    }
};