class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adjList(n+1);
        for(auto road: roads) {
            int u = road[0];
            int v = road[1];
            int wt = road[2];
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }

        queue<int> q;
        q.push(1);

        vector<bool> vis(n+1, false);
        vis[1] = true;

        int minScore = INT_MAX;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto it: adjList[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;

                minScore = min(minScore, edgeWeight);

                if(!vis[adjNode]) {
                    vis[adjNode] = true;
                    q.push(adjNode);
                }
            }
        }

        return minScore;
    }
};