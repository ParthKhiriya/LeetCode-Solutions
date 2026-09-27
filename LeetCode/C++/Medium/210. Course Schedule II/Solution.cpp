class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto it: prerequisites) {
            int dst = it[0];
            int src = it[1];
            adjList[src].push_back(dst);
            indegree[dst]++;
        }

        queue<int> q;
        vector<int> ans;

        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto adjNode: adjList[node]) {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }

        if(ans.size() == numCourses) {
            return ans;
        } else {
            return {};
        }
    }
};