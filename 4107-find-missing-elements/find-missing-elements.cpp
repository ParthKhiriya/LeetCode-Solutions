class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        sort(nums.begin(), nums.end());
        int maxm = nums[n-1];
        int minm = nums[0];

        int num = minm;
        int i = 0;
        while(i < n && num <= maxm) {
            if(nums[i] != num) {
                ans.push_back(num);
            } else {
                i++;
            }
            num++;
        }

        return ans;
    }
};