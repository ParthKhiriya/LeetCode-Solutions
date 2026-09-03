class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_odd = INT_MAX;
        int min_even = INT_MAX;

        for(int i=0; i<nums1.size(); i++) {
            if(nums1[i] % 2 == 0) {
                min_even = min(min_even, nums1[i]);
            } else {
                min_odd = min(min_odd, nums1[i]);
            }
        }

        if(min_odd == INT_MAX) {
            return true;
        }

        return min_odd < min_even;
    }
};