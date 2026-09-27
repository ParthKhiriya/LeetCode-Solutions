class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto it: prerequisites) {
            int dst = it[0];
            int src = it[1];
            adjList[src].push_back(dst);
            indegree[dst]++;
        }

        queue<int> q;
        int count = 0;

        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                count++;
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto adjNode: adjList[node]) {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) {
                    q.push(adjNode);
                    count++;
                }
            }
        }

        return count == numCourses ? true : false;
    }
};