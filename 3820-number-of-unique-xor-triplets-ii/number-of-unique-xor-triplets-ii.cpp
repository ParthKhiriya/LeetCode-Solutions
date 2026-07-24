class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<int> U;
        vector<bool> seen(2048, false);
        for(int num : nums) {
            if(!seen[num]) {
                seen[num] = true;
                U.push_back(num);
            }
        }

        vector<bool> pairXor(2048, false);
        for(int i = 0; i < U.size(); i++) {
            for(int j = i; j < U.size(); j++) {
                pairXor[U[i] ^ U[j]] = true;
            }
        }

        vector<bool> tripletXor(2048, false);
        int unique_count = 0;
        
        for(int p = 0; p < 2048; p++) {
            if(pairXor[p]) {
                for(int u : U) {
                    int final_xor = p ^ u;
                    
                    if(!tripletXor[final_xor]) {
                        tripletXor[final_xor] = true;
                        unique_count++;
                    }
                }
            }
        }

        return unique_count;
    }
};