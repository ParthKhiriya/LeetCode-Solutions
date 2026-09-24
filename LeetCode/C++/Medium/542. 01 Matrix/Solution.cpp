class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        queue<pair<int, int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            int dist = ans[row][col];
            q.pop();

            for(int i=0; i<4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && vis[newRow][newCol] == false) {
                    q.push({newRow, newCol});
                    ans[newRow][newCol] = dist + 1;
                    vis[newRow][newCol] = true;
                }
            }
        }

        return ans;
    }
};