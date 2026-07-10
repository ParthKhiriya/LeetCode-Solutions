class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> V = nums;
        sort(V.begin(), V.end());
        V.erase(unique(V.begin(), V.end()), V.end());
        int M = V.size();
        
        int LOG = 20;
        vector<vector<int>> up(LOG, vector<int>(M, 0));
        
        int j = 0;
        for (int i = 0; i < M; ++i) {
            while (j + 1 < M && V[j + 1] - V[i] <= maxDiff) {
                j++;
            }
            up[0][i] = j;
        }
        
        for (int k = 1; k < LOG; ++k) {
            for (int i = 0; i < M; ++i) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int u = q[0], v = q[1];
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            
            int val_u = nums[u], val_v = nums[v];
            if (val_u == val_v) {
                ans.push_back(1);
                continue;
            }
            
            if (val_u > val_v) swap(val_u, val_v);
            
            int start = lower_bound(V.begin(), V.end(), val_u) - V.begin();
            int target = lower_bound(V.begin(), V.end(), val_v) - V.begin();
            
            if (up[LOG - 1][start] < target) {
                ans.push_back(-1);
                continue;
            }
            
            int curr = start;
            int steps = 0;
            
            for (int k = LOG - 1; k >= 0; --k) {
                if (up[k][curr] < target) {
                    curr = up[k][curr];
                    steps += (1 << k);
                }
            }
            
            ans.push_back(steps + 1);
        }
        
        return ans;
    }
};