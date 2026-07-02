class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> maxHealth(m, vector<int>(n, -1));
        deque<pair<int, pair<int, int>>> dq;

        int startHealth = health - grid[0][0];
        if(startHealth < 1) return false;

        dq.push_front({startHealth, {0, 0}});
        maxHealth[0][0] = startHealth;

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};
        
        while(!dq.empty()) {
            int currHealth = dq.front().first;
            int row = dq.front().second.first;
            int col = dq.front().second.second;
            dq.pop_front();

            if(row == m-1 && col == n-1 && currHealth >= 1) {
                return true;
            }
            
            for(int i=0; i<4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                    int nextHealth = currHealth - grid[newRow][newCol];

                    if(nextHealth >= 1 && nextHealth > maxHealth[newRow][newCol]) {
                        maxHealth[newRow][newCol] = nextHealth;
                        if(grid[newRow][newCol] == 0) {
                            dq.push_front({nextHealth, {newRow, newCol}});
                        } else {
                            dq.push_back({nextHealth, {newRow, newCol}});
                        }
                    }
                }
            }
        }

        return false;
    }
};