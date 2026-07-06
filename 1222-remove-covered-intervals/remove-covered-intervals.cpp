class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<bool> isCovered(n, false);
        int countCovered = 0;

        for(int i=0; i<intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            for(int j=0; j<intervals.size(); j++) {
                if(i != j && !isCovered[j]) {
                    if(start <= intervals[j][0] && end >= intervals[j][1]) {
                        isCovered[j] = true;
                        countCovered++;
                    }
                }
            }
        }

        return (n - countCovered);
    }
};