class Solution {
private: 
    int solve(int i, int j, vector<int>& sv, vector<int>& p, vector<vector<int>>& dp) {
        if (i == j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int res = 0;
        for (int k = i; k < j; k++) {
            int ls = p[k + 1] - p[i];
            int rs = p[j + 1] - p[k + 1];

            if (ls < rs) {
                res = max(res, ls + solve(i, k, sv, p, dp));
            } else if (ls > rs) {
                res = max(res, rs + solve(k + 1, j, sv, p, dp));
            } else {
                res = max(res, ls + max(solve(i, k, sv, p, dp), solve(k + 1, j, sv, p, dp)));
            }
        }
        return dp[i][j] = res;
    }

public:
    int stoneGameV(vector<int>& sv) {
        int n = sv.size();
        vector<int> p(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            p[i + 1] = p[i] + sv[i];
        }
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n - 1, sv, p, dp);
    }
};