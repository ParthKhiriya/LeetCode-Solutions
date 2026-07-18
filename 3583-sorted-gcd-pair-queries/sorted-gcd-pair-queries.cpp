class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = 0;
        for(int num: nums) {
            max_val = max(max_val, num);
        }

        vector<long long> count(max_val+1, 0);
        for(int num: nums) {
            count[num]++;
        }

        vector<long long> gcd(max_val+1, 0);
        for(int i=max_val; i>=1; i--) {
            long long mult_count = 0;

            for(int j=i; j<=max_val; j+=i) {
                mult_count += count[j];
            }

            long long pairs = mult_count * (mult_count - 1) / 2;

            for(int j=2*i; j<=max_val; j+=i) {
                pairs -= gcd[j];
            }

            gcd[i] = pairs;
        }

        vector<long long> prefix(max_val+1, 0);
        for(int i=1; i<=max_val; i++) {
            prefix[i] = prefix[i-1] + gcd[i];
        }

        vector<int> ans;
        for(auto q: queries) {
            int index = upper_bound(prefix.begin(), prefix.end(), q) - prefix.begin();
            ans.push_back(index);
        }

        return ans;
    }
};