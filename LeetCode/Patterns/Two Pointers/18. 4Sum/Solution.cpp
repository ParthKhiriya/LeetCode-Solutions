class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n-3; i++) {
            for(int j=i+1; j<n-2; j++) {
                int currSum = nums[i] + nums[j];
                long long newTarget = (long long)target - (long long)currSum;

                int left = j+1;
                int right = n-1;

                while(left < right) {
                    int sum = nums[left] + nums[right];
                    if(sum == newTarget) {
                        st.insert({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                    } else if (sum > newTarget) {
                        right--;
                    } else {
                        left++;
                    }
                }
            }
        }

        for(auto it: st) {
            ans.push_back(it);
        }

        return ans;
    }
};