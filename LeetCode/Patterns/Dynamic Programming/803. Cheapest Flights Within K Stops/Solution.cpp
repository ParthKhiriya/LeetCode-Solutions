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
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, src});
        dist[src] = 0;
        int stops = 0;

        while(!pq.empty()) {
            int node = pq.top().second;
            int price = pq.top().first;
            pq.pop();

            for(auto it: adjList[node]) {
                int adjNode = it.first;
                int edgeW = it.second;

                if(price + edgeW < dist[adjNode] and stops <= k) {
                    dist[adjNode] = price + edgeW;
                    pq.push({dist[adjNode], adjNode});
                }
            }
            stops++;
        }

        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};