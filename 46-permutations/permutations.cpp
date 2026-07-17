class Solution {
private: 
    void recursion(vector<int>& nums, vector<vector<int>>& ans, vector<int>& possible, vector<bool>& vis) {
        if(possible.size() == nums.size()) {
            ans.push_back(possible);
            return; 
        }

        for(int i=0; i<nums.size(); i++) {
            if(!vis[i]) {
                possible.push_back(nums[i]);
                vis[i] = true;
                recursion(nums, ans, possible, vis);
                possible.pop_back();
                vis[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> possible;
        vector<bool> vis(nums.size(), false);

        recursion(nums, ans, possible, vis);

        return ans;
    }
};