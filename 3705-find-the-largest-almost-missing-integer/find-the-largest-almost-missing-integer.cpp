class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // Case 1: k = n
        if(k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Since nums length is at max 50
        int freq[51] = {0}; 
        for(int i=0; i<n; i++) {
            freq[nums[i]]++;
        }

        // Case 2: k = 1
        if(k == 1) {
            int maxm = -1;
            for(int i=0; i<51; i++) {
                if(freq[i] == 1 && i > maxm) {
                    maxm = i;
                }
            }
            return maxm;
        }

        // Case 3: 1 < k < n
        int ans = -1;
        if(freq[nums[0]] == 1) {
            ans = nums[0];
        }
        if(freq[nums[n-1]] == 1 && nums[n-1] > ans) {
            ans = nums[n-1];
        }

        return ans;
    }
};