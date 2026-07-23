class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;

        int k = 1;
        while(k <= n) {
            k *= 2;
        }

        return k;
    }
};