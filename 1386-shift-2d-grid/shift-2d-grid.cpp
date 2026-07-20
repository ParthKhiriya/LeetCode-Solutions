class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int elements = m * n;

        vector<vector<int>> ans(m, vector<int>(n, 0));

        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                int index = row * n + col;

                int newIndex = (index + k) % elements;

                int newRow = newIndex / n;
                int newCol = newIndex % n;

                ans[newRow][newCol] = grid[row][col];
            }
        }

        return ans;
    }
};