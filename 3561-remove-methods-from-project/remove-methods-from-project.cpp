class Solution {
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adjlist) {
        vis[node] = -1;

        for (int it : adjlist[node]) {
            if (vis[it] != -1) {
                dfs(it, vis, adjlist);
            }
        }
    }

public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> vis(n, 0);
        vector<vector<int>> adjlist(n);

        for (int i = 0; i < invocations.size(); i++) {
            int u = invocations[i][0];
            int v = invocations[i][1];

            adjlist[u].push_back(v);
        }

        // Mark all methods reachable from k
        dfs(k, vis, adjlist);

        // Check if any safe method calls a suspicious method
        for (int i = 0; i < invocations.size(); i++) {
            int u = invocations[i][0];
            int v = invocations[i][1];

            if (vis[u] == 0 && vis[v] == -1) {
                vector<int> ans;
                for (int j = 0; j < n; j++)
                    ans.push_back(j);
                return ans;
            }
        }

        // Remaining methods
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0)
                ans.push_back(i);
        }

        return ans;
    }
};