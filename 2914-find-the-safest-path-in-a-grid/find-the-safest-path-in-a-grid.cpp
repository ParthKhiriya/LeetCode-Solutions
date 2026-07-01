class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    q.push({{i, j}, 0});
                    dist[i][j] = 0;
                }
            }
        }

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
                if(newRow >= 0 && newRow < n && newCol >=0 && newCol < n && dist[newRow][newCol] == -1) {
                    dist[newRow][newCol] = time + 1;
                    q.push({{newRow, newCol}, time+1});
                }
            }
        }

        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> vis(n, vector<int>(n, false));
        pq.push({dist[0][0], {0, 0}});
        vis[0][0] = true;

        while(!pq.empty()) {
            int safenessOfPath = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row == n-1 && col == n-1) {
                return safenessOfPath;
            }

            for(int i=0; i<4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                if(newRow >= 0 && newRow < n && newCol >=0 && newCol < n && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = true;
                    int next_safe = min(safenessOfPath, dist[newRow][newCol]);
                    pq.push({next_safe, {newRow, newCol}});
                }
            }
        }

        return 0;
    }
};