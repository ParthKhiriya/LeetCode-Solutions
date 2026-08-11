class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0] + 1;
        int prefixSum = nums[0];
        int index = 0;

        for(int i=1; i<n; i++) {
            if(nums[i] != nums[i-1] + 1) {
                index = i;
                break;
            }
            prefixSum += nums[i];
        }

        unordered_map<int, bool> mpp;
        for(int i=0; i<n; i++) {
            mpp[nums[i]] = true;
        }

        for(int i=prefixSum; ; i++) {
            if(mpp.find(i) == mpp.end()) {
                return i;
            }
        }
    }
};