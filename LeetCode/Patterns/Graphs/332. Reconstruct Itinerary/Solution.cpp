class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adjList;

        for(const auto& ticket: tickets) {
            adjList[ticket[0]].push_back(ticket[1]);
        }

        // Now let us sort the destinations from a single source in reverse lexicographical order
        for(auto& [src, destinations]: adjList) {
            sort(destinations.rbegin(), destinations.rend());
        }

        stack<string> st;
        vector<string> res;
        st.push("JFK");

        while(!st.empty()) {
            string curr = st.top();

            if(adjList[curr].empty()) {
                res.push_back(curr);
                st.pop();
            } else {
                string next = adjList[curr].back();
                adjList[curr].pop_back();
                st.push(next);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};