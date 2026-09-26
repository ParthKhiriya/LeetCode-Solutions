class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adjList(V);
        vector<int> indegree(V);
        
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            indegree[v]++;
        }
        
        vector<int> ans;
        queue<int> q;
        
        for(int i=0; i<indegree.size(); i++) {
            if(indegree[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(auto adjNode: adjList[node]) {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) {
                    q.push(adjNode);
                    ans.push_back(adjNode);
                }
            }
        }
        
        return ans;
    }
};