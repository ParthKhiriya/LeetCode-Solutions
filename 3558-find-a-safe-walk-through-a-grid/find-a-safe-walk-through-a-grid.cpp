class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        pq.push({health-grid[0][0], {0, 0}});
        vis[0][0] = 1;

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        while(!pq.empty()) {
            int currHealth = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row == m-1 && col == n-1 && currHealth >= 1) {
                return true;
            } else if(currHealth < 1) {
                return false;
            }

            for(int i=0; i<4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = 1;
                    pq.push({currHealth - grid[newRow][newCol], {newRow, newCol}});
                }
            }
        }

        return true;
    }
};