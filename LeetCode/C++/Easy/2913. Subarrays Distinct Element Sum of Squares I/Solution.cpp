class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i=0; i<n; i++) {
            unordered_map<int, bool> mpp;
            int count = 0;
            for(int j=i; j<n; j++) {
                if(mpp.find(nums[j]) == mpp.end() || mpp[nums[j]] == false) {
                    count++;
                }
                mpp[nums[j]] = true;
                ans += count*count;
            }
        }

        return ans;
    }
};