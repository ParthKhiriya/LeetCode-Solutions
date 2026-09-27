class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adjList(n);
        for(auto flight: flights) {
            int u = flight[0];
            int v = flight[1];
            int wt = flight[2];
            adjList[u].push_back({v, wt});
        }

        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {src, 0}});
        dist[src] = 0;

        while(!pq.empty()) {
            int time = pq.top().first;
            int node = pq.top().second.first;
            int stops = pq.top().second.second;
            pq.pop();

            for(auto it: adjList[node]) {
                int adjNode = it.first;
                int edgeW = it.second;

                if(time + edgeW < dist[adjNode] && stops <= k) {
                    dist[adjNode] = time + edgeW;
                    pq.push({dist[adjNode], {adjNode, stops+1}});
                }
            }
        }

        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};