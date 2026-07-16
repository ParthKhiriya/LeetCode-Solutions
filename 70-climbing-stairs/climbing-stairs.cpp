class Solution {
private: 
    int solve(int n, vector<int>& dp) {
        if(dp[n] != 0) return dp[n];
        if(n == 1) return 1;
        if(n == 2) return 2;

        dp[n] = solve(n-1, dp) + solve(n-2, dp);
        return dp[n];
    }

public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        return solve(n, dp);
    }
};