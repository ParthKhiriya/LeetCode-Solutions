class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        mpp[0] = 1;

        int count = 0;
        int runningSum = 0;

        for(int num: nums) {
            runningSum += num;
            int remainder = ((runningSum % k) + k) % k;
            if(mpp.find(remainder) != mpp.end()) {
                count += mpp[remainder];
            }
            mpp[remainder]++;
        }

        return count;
    }
};