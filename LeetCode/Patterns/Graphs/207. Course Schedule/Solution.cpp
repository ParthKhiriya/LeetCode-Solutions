class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto pre: prerequisites) {
            int dst = pre[0];
            int src = pre[1];
            adjList[src].push_back(dst);
            indegree[dst]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int num = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            num++;

            for(auto adjNode: adjList[node]) {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }

        return num == numCourses ? true : false;
    }
};