class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copy = arr;
        sort(copy.begin(), copy.end());

        unordered_map<int, int> mpp;
        int rank = 1;
        for(int i=0; i<copy.size(); i++) {
            if(mpp.find(copy[i]) != mpp.end()) {
                continue;
            }
            mpp[copy[i]] = rank;
            rank++;
        }

        for(int i=0; i<arr.size(); i++) {
            arr[i] = mpp[arr[i]];
        }

        return arr;
    }
};