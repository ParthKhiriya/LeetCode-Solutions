class Solution {
    long long g(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    long long c(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / g(a, b)) * b;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        vector<long long> l;
        vector<int> s;
        long long m = 50000000000LL;

        for (int i = 1; i < (1 << n); i++) {
            long long v = 1;
            int b = 0;
            
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    v = c(v, coins[j]);
                    b++;
                    if (v > m) {
                        break;
                    }
                }
            }
            
            if (v <= m) {
                l.push_back(v);
                if (b % 2 == 1) {
                    s.push_back(1);
                } else {
                    s.push_back(-1);
                }
            }
        }

        long long low = 1;
        long long high = m;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long cnt = 0;

            for (int i = 0; i < l.size(); i++) {
                cnt += s[i] * (mid / l[i]);
            }

            if (cnt >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};