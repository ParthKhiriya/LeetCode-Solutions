class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1000000007;

        // Create a 3D array. 
        // dp[r][c][0] = stores the maximum path sum to reach (r, c)
        // dp[r][c][1] = number of ways to achieve this max sum
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(n+1, {0, 0}));

        dp[n-1][n-1][0] = 0;
        dp[n-1][n-1][1] = 1; // There is one way to reach at the starting point.

        for(int r=n-1; r>=0; r--) {
            for(int c=n-1; c>=0; c--) {
                if(board[r][c] == 'X' || (r == n-1 && c == n-1)) {
                    continue;
                }

                long long max_path_sum = -1;

                if(dp[r+1][c][1] > 0) max_path_sum = max(max_path_sum, dp[r+1][c][0]);
                if(dp[r][c+1][1] > 0) max_path_sum = max(max_path_sum, dp[r][c+1][0]);
                if(dp[r+1][c+1][1] > 0) max_path_sum = max(max_path_sum, dp[r+1][c+1][0]);

                if(max_path_sum != -1) {
                    long long ways = 0;

                    if(dp[r+1][c][1] > 0 && dp[r+1][c][0] == max_path_sum) {
                        ways = (ways + dp[r+1][c][1]) % MOD;
                    }
                    if(dp[r][c+1][1] > 0 && dp[r][c+1][0] == max_path_sum) {
                        ways = (ways + dp[r][c+1][1]) % MOD;
                    }
                    if(dp[r+1][c+1][1] > 0 && dp[r+1][c+1][0] == max_path_sum) {
                        ways = (ways + dp[r+1][c+1][1]) % MOD;
                    }

                    int val = 0;
                    if(board[r][c] >= '1' && board[r][c] <= '9') {
                        val = board[r][c] - '0';
                    }

                    dp[r][c][0] = max_path_sum + val;
                    dp[r][c][1] = ways;
                }
            }
        }

        return {(int)dp[0][0][0], (int)dp[0][0][1]};
    }
};