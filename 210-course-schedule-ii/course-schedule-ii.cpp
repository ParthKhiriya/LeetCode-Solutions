class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adjList(n);
        vector<int> indegree(n, 0);

        for(auto pre: prerequisites) {
            int dst = pre[0];
            int src = pre[1];
            adjList[src].push_back(dst);
            indegree[dst]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);

            for(auto adjNode: adjList[node]) {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }

        if(order.size() != numCourses) {
            return {};
        }

        return order;
    }
};