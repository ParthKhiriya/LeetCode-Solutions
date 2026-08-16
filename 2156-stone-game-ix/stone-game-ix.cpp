class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int c0 = 0;
        int c1 = 0;
        int c2 = 0;

        for(int i=0; i<stones.size(); i++) {
            int remainder = stones[i] % 3;
            if(remainder == 0) c0++;
            else if (remainder == 1) c1++;
            else c2++;
        }

        if(c0 % 2 == 0) {
            return c1 > 0 && c2 > 0;
        } else {
            return (c1 - c2 > 2) || (c2 - c1 > 2);
        }
    }
};