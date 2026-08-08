class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> suff(m, -1);
        int j = n-1;

        for(int i=m-1; i>=0; i--) {
            while(j >= 0 && word1[j] != word2[i]) {
                j--;
            }
            
            if(j < 0) break;
            suff[i] = j;
            j--;
        }

        vector<int> ans;
        bool changed = false;
        j = 0;

        for(int i=0; i<m && j<n; ) {
            if(word1[j] == word2[i]) {
                ans.push_back(j);
                i++;
                j++;
            } else if (!changed && (i+1 == m || suff[i+1] > j)) {
                changed = true;
                ans.push_back(j);
                i++;
                j++;
            } else {
                j++;
            }
        }

        if(ans.size() == m) {
            return ans;
        }

        return {};
    }
};