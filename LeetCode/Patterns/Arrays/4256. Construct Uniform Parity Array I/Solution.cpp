class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        
        bool odd = true;
        bool even = true;

        // Let us first do the odd case check
        for(int i=0; i<n; i++) {
            if(nums1[i] % 2 == 0) {
                for(int j=0; j<n; j++) {
                    if(i != j && (nums1[i] - nums1[j]) % 2 != 0) {
                        break;
                    } else if (i != j) {
                        odd = false;
                    }
                }
            }
        }

        // Now let us check for the even case
        for(int i=0; i<n; i++) {
            if(nums1[i] % 2 != 0) {
                for(int j=0; j<n; j++) {
                    if(i != j && (nums1[i] - nums1[j]) % 2 == 0) {
                        break;
                    } else if (i != j) {
                        even = false;
                    }
                }
            }
        }

        return odd || even; 
    }
};