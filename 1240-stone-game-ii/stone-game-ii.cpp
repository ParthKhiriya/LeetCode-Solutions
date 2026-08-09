class Solution {
private: 
    int solve(int i, int M, vector<int>& piles, vector<int>& suffixSum, vector<vector<int>>& memo) {
        int n = piles.size();

        if(i + 2*M >= n) return suffixSum[i];
        if(memo[i][M] != -1) return memo[i][M];

        int min_opponent_score = 1e9;
        for(int X=1; X<=2*M; X++) {
            int opponent_score = solve(i+X, max(X, M), piles, suffixSum, memo);
            min_opponent_score = min(min_opponent_score, opponent_score);
        }

        return memo[i][M] = suffixSum[i] - min_opponent_score;
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int> suffixSum(n, 0);
        suffixSum[n-1] = piles[n-1];
        for(int i=n-2; i>=0; i--) {
            suffixSum[i] = suffixSum[i+1] + piles[i];
        }

        vector<vector<int>> memo(n, vector<int> (n+1, -1));

        return solve(0, 1, piles, suffixSum, memo);
    }
};