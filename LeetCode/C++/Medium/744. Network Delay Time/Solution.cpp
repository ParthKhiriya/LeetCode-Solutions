class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjList(n+1);

        for(auto edge: times) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adjList[u].push_back({v, wt});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        while(!pq.empty()) {
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();

            for(auto it: adjList[node]) {
                int adjNode = it.first;
                int edgeW = it.second;

                if(time + edgeW < dist[adjNode]) {
                    dist[adjNode] = time + edgeW;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int minTime = -1;
        for(int i=1; i<=n; i++) {
            if(dist[i] == INT_MAX) {
                return -1;
            } else {
                minTime = max(minTime, dist[i]);
            }
        }

        return minTime;
    }
};