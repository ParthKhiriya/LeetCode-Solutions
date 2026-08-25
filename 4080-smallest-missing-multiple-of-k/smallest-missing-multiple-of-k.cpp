class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, bool> mpp;

        for(int i=0; i<n; i++) {
            mpp[nums[i]] = true;
        }

        for(int i=1; ; i++) {
            if(mpp.find(k * i) == mpp.end()) {
                return k * i;
            }
        }
    }
};