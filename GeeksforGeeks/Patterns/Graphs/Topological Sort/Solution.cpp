class Solution {
  private: 
    void dfs(vector<vector<int>>& adjList, vector<bool>& vis, stack<int>& st, int node) {
        vis[node] = true;
        
        for(auto adjNode: adjList[node]) {
            if(vis[adjNode] == false) {
                dfs(adjList, vis, st, adjNode);
            }
        }
        
        st.push(node);
    }
    
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        int n = V;
        vector<vector<int>> adjList(n);
        vector<bool> vis(n, false);
        vector<int> ans;
        
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
        }
        
        stack<int> st;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                dfs(adjList, vis, st, i);
            }
        }
        
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};