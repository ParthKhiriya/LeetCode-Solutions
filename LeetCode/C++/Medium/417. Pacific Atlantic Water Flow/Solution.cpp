class Solution {
private: 
    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& vis) {
        int m = heights.size();
        int n = heights[0].size();

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && heights[newRow][newCol] >= heights[row][col] && vis[newRow][newCol] == false) {
                    q.push({newRow, newCol});
                    vis[newRow][newCol] = true;
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        queue<pair<int, int>> pq;
        queue<pair<int, int>> aq;

        vector<vector<bool>> visp(m, vector<bool>(n, false));
        vector<vector<bool>> visa(m, vector<bool>(n, false));

        for(int i=0; i<m; i++) {
            pq.push({i, 0});
            visp[i][0] = true;
            aq.push({i, n-1});
            visa[i][n-1] = true;
        }
        for(int i=0; i<n; i++) {
            pq.push({0, i});
            visp[0][i] = true;
            aq.push({m-1, i});
            visa[m-1][i] = true;
        }

        bfs(heights, pq, visp);
        bfs(heights, aq, visa);

        vector<vector<int>> result;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(visp[i][j] && visa[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};