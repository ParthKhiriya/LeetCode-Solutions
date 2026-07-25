class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) {
            return 0;
        }

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for(int i=1; i<m; i++) {
            if(obstacleGrid[i][0] == 1) break;
            dp[i][0] = dp[i-1][0];
        }

        for(int j=1; j<n; j++) {
            if(obstacleGrid[0][j] == 1) break;
            dp[0][j] = dp[0][j-1];
        }

        for(int row = 1; row < m; row++) {
            for(int col = 1; col < n; col++) {
                if(obstacleGrid[row][col] == 1) {
                    dp[row][col] = 0;
                } else {
                    dp[row][col] = dp[row-1][col] + dp[row][col-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};