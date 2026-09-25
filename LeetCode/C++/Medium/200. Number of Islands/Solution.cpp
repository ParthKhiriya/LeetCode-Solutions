using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;

class Solution {
private: 
    void bfs(int i, int j, vvc& grid, vvb& vis, int& islands, int m, int n) {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int k=0; k<4; k++) {
                int newRow = row + delRow[k];
                int newCol = col + delCol[k];

                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && vis[newRow][newCol] == false && grid[newRow][newCol] == '1') {
                    q.push({newRow, newCol});
                    vis[newRow][newCol] = true;
                }
            }
        }
        islands++;
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int islands = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1' && vis[i][j] == false) {
                    bfs(i, j, grid, vis, islands, m, n);
                }
            }
        }

        return islands;
    }
};