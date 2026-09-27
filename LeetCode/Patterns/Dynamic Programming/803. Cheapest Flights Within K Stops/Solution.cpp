class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adjList(n);
        for(auto it: flights) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adjList[u].push_back({v, wt});
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int steps = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            for(auto it1 : adjList[node]) {
                int adjNode = it1.first;
                int weight = it1.second;

                if(cost + weight < dist[adjNode] && steps <= k) {
                    dist[adjNode] = cost + weight;
                    q.push({steps+1, {adjNode, dist[adjNode]}});
                }
            }
        }

        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};