class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int zero = cost[0];
        int one = cost[1];

        for(int i=2; i<n; i++) {
            int result = cost[i] + min(one, zero);
            zero = one;
            one = result;
        }

        return min(one, zero);
    }
};