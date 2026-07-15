class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        int time = 0;

        queue<pair<int, int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                } else if(grid[i][j] == 1) {
                    count++;
                }
            }
        }

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        while(count > 0 && !q.empty()) {
            int length = q.size();
            for(int i=0; i<length; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(int i=0; i<4; i++) {
                    int newRow = row + delRow[i];
                    int newCol = col + delCol[i];

                    if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                        count--;
                    }
                }
            }
            time++;
        }

        return count == 0 ? time : -1;
    }
};