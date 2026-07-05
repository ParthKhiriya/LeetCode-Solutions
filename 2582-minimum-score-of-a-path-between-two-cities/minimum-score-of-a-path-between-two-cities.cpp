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

        // Now, since it is given that there exist atleast one path between 1 and n, that means 1 and n are always in the same component. 
        int min_score = INT_MAX;
        queue<int> q;
        q.push(1);

        vector<bool> vis(n+1, false);
        vis[1] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto it: adjList[node]) {
                int adjNode = it.first;
                int adjWeight = it.second;
                min_score = min(min_score, adjWeight);

                if(!vis[adjNode]) {
                    vis[adjNode] = true;
                    q.push(adjNode);
                }
            }
        }

        return min_score;

    }
};