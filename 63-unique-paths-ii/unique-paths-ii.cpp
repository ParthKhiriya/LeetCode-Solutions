class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) {
            return 0;
        }

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> dp(n);
        dp[0] = 1;

        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(obstacleGrid[row][col] == 1) {
                    dp[col] = 0;
                } else if(col > 0) {
                    dp[col] += dp[col-1];
                }
            }
        }

        return dp[n-1];
    }
};