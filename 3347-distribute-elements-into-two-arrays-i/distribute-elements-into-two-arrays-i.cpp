class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> r1;
        vector<int> r2;

        r1.push_back(nums[0]);
        r2.push_back(nums[1]);

        for(int i=2; i<n; i++) {
            if(r1.back() > r2.back()) {
                r1.push_back(nums[i]);
            } else {
                r2.push_back(nums[i]);
            }
        }

        for(int i=0; i<r2.size(); i++) {
            r1.push_back(r2[i]);
        }

        return r1;
    }
};