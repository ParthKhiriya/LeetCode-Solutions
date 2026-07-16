class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n, 0);
        int curr_max = INT_MIN;

        for(int i=0; i<n; i++) {
            curr_max = max(curr_max, nums[i]);
            prefixGcd[i] = gcd(nums[i], curr_max);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int left = 0;
        int right = n-1;
        long long sum = 0;

        while(left < right) {
            sum += gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }

        return sum;
    }
};