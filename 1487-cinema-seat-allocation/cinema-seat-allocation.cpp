class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mpp;

        for(auto& s: reservedSeats) {
            if(s[1] >= 2 && s[1] <= 5) mpp[s[0]] |= 1;
            if(s[1] >= 4 && s[1] <= 7) mpp[s[0]] |= 2;
            if(s[1] >= 6 && s[1] <= 9) mpp[s[0]] |= 4;
        }

        int ans = (n - mpp.size()) * 2;

        for(auto& it: mpp) {
            int v = it.second;

            if(((v & 1) == 0) && ((v & 4) == 0)) {
                ans += 2;
            } else if(((v & 1) == 0) || ((v & 2) == 0) || ((v & 4) == 0)) {
                ans += 1;
            }
        }

        return ans;
    }
};