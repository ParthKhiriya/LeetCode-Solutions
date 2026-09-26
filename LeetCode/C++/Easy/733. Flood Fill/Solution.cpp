class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int color, int delRow[], int delCol[], int startColor) {
        int n = image.size();
        int m = image[0].size();

        ans[row][col] = color;
        for(int i=0; i<4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == startColor && ans[nrow][ncol] != color) {
                dfs(nrow, ncol, ans, image, color, delRow, delCol, startColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Below given is the DFS Approahc for solving this question.
        int startColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        dfs(sr, sc, ans, image, color, delRow, delCol, startColor);

        return ans;
        
        // Below is the BFS Approach for solving this question.
        
        // int n = image.size();
        // int m = image[0].size();

        // queue<pair<int, int>> q;
        // int startColor = image[sr][sc];
        // if (startColor == color) return image;
        // image[sr][sc] = color;

        // q.push({sr, sc});
        // int delRow[] = {-1, 0, 1, 0};
        // int delCol[] = {0, 1, 0, -1};

        // while(!q.empty()) {
        //     int row = q.front().first;
        //     int col = q.front().second;
        //     q.pop();

        //     for(int i=0; i<4; i++) {
        //         int nrow = row + delRow[i];
        //         int ncol = col + delCol[i];

        //         if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == startColor) {
        //             q.push({nrow, ncol});
        //             image[nrow][ncol] = color;
        //         }
        //     }
        // }

        // return image;
    }
};