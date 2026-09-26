class Solution {
private: 
    bool checkBipartite(vector<vector<int>>& graph, int start, vector<int>& vis, int color) {
        vis[start] = color;

        for(auto adjNode: graph[start]) {
            if(vis[adjNode] == -1) {
                if(checkBipartite(graph, adjNode, vis, !color) == false) return false;
            } else if(vis[adjNode] == vis[start]) {
                return false;
            }
        }

        return true;

        // BFS Approach:

        // int n = graph.size();
        // queue<int> q;
        // q.push(start);
        // vis[start] = 0;

        // while(!q.empty()) {
        //     int node = q.front();
        //     q.pop();

        //     for(auto adjNode: graph[node]) {
        //         if(vis[adjNode] == -1) {
        //             vis[adjNode] = !vis[node];
        //             q.push(adjNode);
        //         } else if(vis[adjNode] == vis[node]) {
        //             return false;
        //         }
        //     }
        // }
        // return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        int color = 0;
        for(int i=0; i<n; i++) {
            if(vis[i] == -1) {
                if(checkBipartite(graph, i, vis, color) == false) return false;
            }
        }
        return true;
    }
};