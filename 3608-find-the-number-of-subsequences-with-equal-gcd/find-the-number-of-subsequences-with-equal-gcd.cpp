class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int MOD = 1e9 + 7;
        int n = nums.size();
        int max_val = *max_element(nums.begin(), nums.end());

        vector<vector<int>> dp(max_val+1, vector<int>(max_val+1, 0));
        dp[0][0] = 1;

        for(int num: nums) {
            vector<vector<int>> next_dp(max_val+1, vector<int>(max_val+1, 0));

            for(int g1=0; g1<=max_val; g1++) {
                for(int g2=0; g2<=max_val; g2++) {
                    if(dp[g1][g2] == 0) continue;
                    int ways = dp[g1][g2];

                    next_dp[g1][g2] = (next_dp[g1][g2] + ways) % MOD;

                    int next_g1 = gcd(g1, num);
                    next_dp[next_g1][g2] = (next_dp[next_g1][g2] + ways) % MOD;

                    int next_g2 = gcd(g2, num);
                    next_dp[g1][next_g2] = (next_dp[g1][next_g2] + ways) % MOD;
                }
            }
            dp = move(next_dp);
        }

        int total_ways = 0;
        for(int i=1; i<=max_val; i++) {
            total_ways = (total_ways + dp[i][i]) % MOD;
        }

        return total_ways;
    }
};