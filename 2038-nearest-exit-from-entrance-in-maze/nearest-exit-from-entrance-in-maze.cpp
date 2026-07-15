class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        queue<pair<pair<int, int>, int>> q;

        for(int i=0; i<m; i++) {
            if(maze[i][0] == '.') {
                if(entrance[0] != i || entrance[1] != 0)
                    q.push({{i, 0}, 0});
                    vis[i][0] = true;
            }
            if(maze[i][n-1] == '.') {
                if(entrance[0] != i || entrance[1] != n-1)
                    q.push({{i, n-1}, 0});
                    vis[i][n-1] = true;
            }
        }

        for(int i=0; i<n; i++) {
            if(maze[0][i] == '.') {
                if(entrance[0] != 0 || entrance[1] != i)
                    q.push({{0, i}, 0});
                    vis[0][i] = true;
            }
            if(maze[m-1][i] == '.') {
                if(entrance[0] != m-1 || entrance[1] != i)
                    q.push({{m-1, i}, 0});
                    vis[m-1][i] = true;
            }
        }


        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow == entrance[0] && newCol == entrance[1]) {
                    return steps + 1;
                }

                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !vis[newRow][newCol] && maze[newRow][newCol] == '.') {
                    vis[newRow][newCol] = true;
                    int newSteps = steps + 1;
                    q.push({{newRow, newCol}, newSteps});
                }
            }
        }

        return -1;
    }
};