class Solution {
public:
    bool check(int min_score, vector<vector<pair<int, int>>>& adjList, vector<bool>& online, long long k, int n) {
        vector<long long> dist(n, 1e18);
        dist[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while(!pq.empty()) {
            int node = pq.top().second;
            int distance = pq.top().first;
            pq.pop();

            if(distance > dist[node]) {
                continue;
            }

            if(node == n-1) {
                return dist[node] <= k;
            }

            for(auto it: adjList[node]) {
                int adjNode = it.first;
                int edgeW = it.second;

                if(edgeW < min_score) {
                    continue;
                }

                if(!online[adjNode]) {
                    continue;
                }

                if(dist[node] + edgeW < dist[adjNode]) {
                    dist[adjNode] = dist[node] + edgeW;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist[n-1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adjList(n);
        int maxWeight = 0;

        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adjList[u].push_back({v, wt});
            maxWeight = max(maxWeight, wt);
        }

        int low = 0;
        int high = maxWeight;
        int bestScore = -1;

        while(low <= high) {
            int mid = low + (high-low)/2;

            if(check(mid, adjList, online, k, n)) {
                bestScore = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return bestScore;
    }
};