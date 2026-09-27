class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adjList(n+1);
        vector<int> degree(n+1, 0);

        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        for(int i=1; i<=n; i++) {
            if(degree[i] == 1) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            degree[node]--;

            for(auto it: adjList[node]) {
                degree[it]--;
                if(degree[it] == 1) {
                    q.push(it);
                }
            }
        }

        for(int i=edges.size()-1; i>=0; i--) {
            int u = edges[i][0];
            int v = edges[i][1];
            if(degree[u] > 0 && degree[v] > 0) {
                return {u, v};
            }
        }

        return {};
    }
};