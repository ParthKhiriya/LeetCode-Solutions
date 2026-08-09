class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int count = 0;

        int runningSum = 0;
        for(int num: nums) {
            runningSum += num;
            if(mpp.find(runningSum - k) != mpp.end()) {
                count += mpp[runningSum - k];
            }
            mpp[runningSum]++;
        }

        return count;
    }
};