class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        if(grid[0][0] == 1) return -1;

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        dist[0][0] = 1;

        while(!q.empty()) {
            int distance = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            int delRow[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
            int delCol[8] = {0, 1, 1, 1, 0, -1, -1, -1};

            for(int i=0; i<8; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0 && distance + 1 < dist[nrow][ncol]) {
                    if(nrow == n-1 && ncol == n-1) return distance + 1;
                    q.push({distance + 1, {nrow, ncol}});
                    dist[nrow][ncol] = distance + 1;
                }
            }
        }

        if(dist[n-1][n-1] == INT_MAX) return -1;
        return dist[n-1][n-1];
    }
};