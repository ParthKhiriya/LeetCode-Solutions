class Solution {
public:
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        queue<pair<int, int>> pacific;
        queue<pair<int, int>> atlantic;

        for(int i=0; i<m; i++) {
            pacific.push({i, 0});
            atlantic.push({i, n-1});
        }

        for(int i=0; i<n; i++) {
            pacific.push({0, i});
            atlantic.push({m-1, i});
        }

        bfs(pacific, pac, heights);
        bfs(atlantic, atl, heights);

        vector<vector<int>> result;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(pac[i][j] && atl[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            ocean[row][col] = true;

            for(int i=0; i<4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 && newRow < heights.size() && newCol >= 0 && newCol < heights[0].size() && !ocean[newRow][newCol] && heights[newRow][newCol] >= heights[row][col]) {
                    q.push({newRow, newCol});
                }
            }
        }
    }
};