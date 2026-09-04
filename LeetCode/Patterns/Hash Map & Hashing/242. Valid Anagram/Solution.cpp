class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mpps;
        int n = s.size();
        int m = t.size();

        if(n != m) return false;

        for(int i=0; i<n; i++) {
            mpps[s[i]]++;
            mpps[t[i]]--;
        }
        for(auto it: mpps) {
            if(it.second != 0) return false;
        }
        return true;
    }
};