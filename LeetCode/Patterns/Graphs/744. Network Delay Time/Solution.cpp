class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjList(n+1);
        for(auto it: times) {
            int src = it[0];
            int tgt = it[1];
            int time = it[2];
            adjList[src].push_back({tgt, time});
        }

        queue<pair<int, int>> q;
        q.push({k, 0});
        vector<int> distance(n+1, INT_MAX);
        distance[k] = 0;

        while(!q.empty()) {
            int node = q.front().first;
            int time = q.front().second;
            q.pop();

            for(auto it: adjList[node]) {
                int adjNode = it.first;
                int edgeW = it.second;
                if(time + edgeW < distance[adjNode]) {
                    distance[adjNode] = time + edgeW;
                    q.push({adjNode, distance[adjNode]});
                }
            }
        }

        int minTime = 0;
        for(int i=1; i<=n; i++) {
            if(distance[i] == INT_MAX) {
                return -1;
            } else {
                minTime = max(minTime, distance[i]);
            }
        }

        return minTime;
    }
};