class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<bool> vis(n, false);
        int count = 0;

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                vis[i] = true;
                queue<int> q;
                q.push(i);

                int v_count = 0;
                int e_count = 0;

                while(!q.empty()) {
                    int node = q.front();
                    q.pop();

                    v_count++; // We found a vertex
                    e_count += adjList[node].size();

                    for(auto adjNode: adjList[node]) {
                        if(!vis[adjNode]) {
                            vis[adjNode] = true;
                            q.push(adjNode);
                        }
                    }
                }

                if (e_count == v_count * (v_count - 1)) {
                    count++;
                }
            }
        }

        return count;
    }
};