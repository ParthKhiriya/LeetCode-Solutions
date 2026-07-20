class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dummy = grid;

        for(int i=0; i<k; i++) {
            for(int i=0; i<m-1; i++) {
                dummy[i+1][0] = grid[i][n-1];
            }

            dummy[0][0] = grid[m-1][n-1];

            for(int i=0; i<m; i++) {
                for(int j=0; j<n-1; j++) {
                    dummy[i][j+1] = grid[i][j];
                }
            }

            grid = dummy;
        }

        return grid;
    }
};