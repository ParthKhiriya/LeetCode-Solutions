class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxm = *max_element(nums.begin(), nums.end());
        int moves = 0;

        for(auto num: nums) {
            moves += maxm - num;
        }

        return moves;
    }
};