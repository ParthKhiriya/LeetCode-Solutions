class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> safe(n, vector<int>(n, -1));

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;

        queue<pair<int, int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    safe[i][j] = 0;
                }
            }
        }

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 && newCol >= 0 && newRow < n && newCol < n && safe[newRow][newCol] == -1) {
                    safe[newRow][newCol] = safe[row][col] + 1;
                    q.push({newRow, newCol});
                }
            }
        }

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({safe[0][0], {0, 0}});
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[0][0] = true;

        while(!pq.empty()) {
            int safeness = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row == n-1 && col == n-1) {
                return safeness;
            }

            for(int i=0; i<4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 && newCol >= 0 && newRow < n && newCol < n && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = true;
                    int newSafe = min(safeness, safe[newRow][newCol]);
                    pq.push({newSafe, {newRow, newCol}});
                }
            }
        }

        return 0;
    }
};