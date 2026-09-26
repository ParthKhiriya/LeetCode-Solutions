class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> newGraph(n);
        vector<int> ans;
        queue<int> q;
        vector<int> indegree(n, 0);

        for(int i=0; i<n; i++) {
            for(int j: graph[i]) {
                newGraph[j].push_back(i);
                indegree[i]++;
            }
        }

        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto adjNode: newGraph[node]) {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) q.push(adjNode);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};