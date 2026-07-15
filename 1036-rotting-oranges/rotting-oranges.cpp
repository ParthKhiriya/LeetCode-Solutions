class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                } else if(grid[i][j] == 1) {
                    count++;
                }
            }
        }

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !vis[newRow][newCol] && grid[newRow][newCol] == 1) {
                    vis[newRow][newCol] = true;
                    int newTime = time + 1;
                    q.push({{newRow, newCol}, newTime});
                    count--;
                    if(count == 0) {
                        return newTime;
                    }
                }
            }
        }

        return count == 0 ? 0 : -1;
    }
};