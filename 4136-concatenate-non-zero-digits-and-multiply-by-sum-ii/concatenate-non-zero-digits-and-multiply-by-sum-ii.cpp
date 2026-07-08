class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        long long MOD = 1000000007;

        vector<int> nonZeros;
        vector<int> cnt(n, 0);
        int current_cnt = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                nonZeros.push_back(s[i] - '0');
                current_cnt++;
            }
            cnt[i] = current_cnt;
        }

        int k = nonZeros.size();

        vector<long long> pow10(k + 1, 1);
        for (int i = 1; i <= k; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        vector<long long> P(k + 1, 0);
        vector<long long> S(k + 1, 0);

        for (int i = 1; i <= k; i++) {
            P[i] = (P[i - 1] * 10 + nonZeros[i - 1]) % MOD;
            S[i] = S[i - 1] + nonZeros[i - 1];
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];
            
            int L = (l == 0) ? 1 : cnt[l - 1] + 1;
            int R = cnt[r];

            if (L > R) {
                ans.push_back(0);
            } else {
                long long shift = (P[L - 1] * pow10[R - L + 1]) % MOD;
                long long x = (P[R] - shift + MOD) % MOD;
                long long sum = S[R] - S[L - 1];
                long long res = (x * (sum % MOD)) % MOD;
                ans.push_back((int)res);
            }
        }
        
        return ans;
    }
};