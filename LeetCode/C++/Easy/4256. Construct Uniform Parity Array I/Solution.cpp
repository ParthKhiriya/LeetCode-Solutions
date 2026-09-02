class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        
        bool odd = true;
        bool even = true;

        // Let us first do the odd case check
        for(int i=0; i<n; i++) {
            if(nums1[i] % 2 == 0) {
                bool found = false;
                for(int j=0; j<n; j++) {
                    if(i != j && (nums1[i] - nums1[j]) % 2 != 0) {
                        found = true;
                        break;
                    }
                }
                if(!found) {
                    odd = false;
                    break;
                }
            }
        }

        // Now let us check for the even case
        for(int i=0; i<n; i++) {
            if(nums1[i] % 2 != 0) {
                bool found = false;
                for(int j=0; j<n; j++) {
                    if(i != j && (nums1[i] - nums1[j]) % 2 == 0) {
                        found = true;
                        break;
                    }
                }
                if(!found) {
                    even = false;
                    break;
                }
            }
        }

        return odd || even; 
    }
};