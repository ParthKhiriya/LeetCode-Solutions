class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int initial_ones = 0;
        for(char c: s) {
            if(c == '1') initial_ones++;
        }

        string t = '1' + s + '1';

        vector<pair<char, int>> rle;
        for(int i=0; i<t.length(); i++) {
            int count = 1;
            while(i+1 < t.length() && t[i] == t[i+1]) {
                count++;
                i++;
            }
            rle.push_back({t[i], count});
        }

        vector<int> zeros;
        vector<int> ones;

        for(int i=0; i<rle.size(); i++) {
            if(rle[i].first == '0') {
                zeros.push_back(rle[i].second);
            } else {
                if(i != 0 && i != rle.size()-1) {
                    ones.push_back(rle[i].second);
                }
            }
        }

        int k = zeros.size();
        if(k < 2) return initial_ones;

        vector<int> pref(k, 0), suff(k, 0);
        pref[0] = zeros[0];
        for(int i=1; i<k; i++) {
            pref[i] = max(pref[i-1], zeros[i]);
        }

        suff[k-1] = zeros[k-1];
        for(int i=k-2; i>=0; i--) {
            suff[i] = max(suff[i+1], zeros[i]);
        }

        int max_gain = 0;
        for(int i=0; i<k-1; i++) {
            int gainA = zeros[i] + zeros[i+1];
            max_gain = max(max_gain, gainA);

            int max_distant_zero = 0;
            if(i-1 >= 0) max_distant_zero = max(max_distant_zero, pref[i-1]);
            if(i+2 < k) max_distant_zero = max(max_distant_zero, suff[i+2]);

            int gainB = max_distant_zero - ones[i];
            max_gain = max(max_gain, gainB);
        }

        return initial_ones + max_gain;
    }
};