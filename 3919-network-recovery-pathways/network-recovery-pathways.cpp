class Solution {
public:
    bool check(int min_score, vector<bool>& online, vector<vector<pair<int, int>>> adjList, long long k, int n) {
        vector<long long> dist(n, 1e18);
        dist[0] = 0;

        // The priority queue takes {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while(!pq.empty()) {
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(cost > dist[node]) {
                continue;
            }

            if(node == n-1) {
                return dist[node] <= k;
            }

            for(auto& it: adjList[node]) {
                int adjNode = it.first;
                int adjWeight = it.second;

                if(!online[adjNode]) {
                    continue;
                }

                if(adjWeight < min_score) {
                    continue;
                }

                if(dist[node] + adjWeight < dist[adjNode]) {
                    dist[adjNode] = dist[node] + adjWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist[n-1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        // First we create an adjacency list from the given edges
        int n = online.size();

        vector<vector<pair<int, int>>> adjList(n);
        int max_weight = 0;
        for(auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adjList[u].push_back({v, wt});
            max_weight = max(max_weight, wt);
        }

        // Now since we got out max_weight, so we have to maximum possible answer
        int low = 0;
        int high = max_weight;
        int best_score = -1;

        // Begin the binary search on answers
        while(low <= high) {
            int mid = low + (high-low)/2;

            if(check(mid, online, adjList, k, n)) {
                best_score = mid;
                low = mid+1;
            } else {
                high = mid - 1;
            }
        }

        return best_score;
    }
};