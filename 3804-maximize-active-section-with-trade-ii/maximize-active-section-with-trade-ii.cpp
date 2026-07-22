#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    struct Node {
        long long maxZ, maxZ_excl_right, maxZ_excl_left;
        long long maxA, maxNegO, maxLtoR, maxRtoL;
        long long firstZ, lastZ;
        
        // Constructor for a single zero-block
        Node(long long z_val = -1e15) {
            if (z_val > -1e14) {
                maxZ = firstZ = lastZ = z_val;
                maxZ_excl_right = maxZ_excl_left = -1e15;
                maxA = maxNegO = maxLtoR = maxRtoL = -1e15;
            } else {
                maxZ = firstZ = lastZ = -1e15;
                maxZ_excl_right = maxZ_excl_left = -1e15;
                maxA = maxNegO = maxLtoR = maxRtoL = -1e15;
            }
        }
    };

    vector<Node> tree;

    Node mergeNodes(const Node& left, const Node& right, long long O_mid) {
        if (left.maxZ <= -1e14) return right;
        if (right.maxZ <= -1e14) return left;
        
        Node res;
        res.firstZ = left.firstZ;
        res.lastZ = right.lastZ;
        
        res.maxZ = max(left.maxZ, right.maxZ);
        res.maxZ_excl_right = max(left.maxZ, right.maxZ_excl_right);
        res.maxZ_excl_left = max(left.maxZ_excl_left, right.maxZ);
        
        // Option A: Either fully inside left/right, or crossing the boundary
        res.maxA = max({left.maxA, right.maxA, left.lastZ + right.firstZ});
        
        res.maxNegO = max({left.maxNegO, right.maxNegO, -O_mid});
        
        // Distant combinations crossing the boundary
        res.maxLtoR = max({left.maxLtoR, right.maxLtoR, 
                           left.maxZ + right.maxNegO, 
                           left.maxZ_excl_right - O_mid});
                           
        res.maxRtoL = max({left.maxRtoL, right.maxRtoL, 
                           right.maxZ + left.maxNegO, 
                           right.maxZ_excl_left - O_mid});
        return res;
    }

    void build(int node, int l, int r, const vector<long long>& Z, const vector<long long>& O) {
        if (l == r) {
            tree[node] = Node(Z[l]);
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * node, l, mid, Z, O);
        build(2 * node + 1, mid + 1, r, Z, O);
        tree[node] = mergeNodes(tree[2 * node], tree[2 * node + 1], O[mid]);
    }

    Node query(int node, int l, int r, int ql, int qr, const vector<long long>& O) {
        if (ql > r || qr < l) return Node(); // Returns empty node (-INF)
        if (ql <= l && r <= qr) return tree[node];
        
        int mid = l + (r - l) / 2;
        Node left_node = query(2 * node, l, mid, ql, qr, O);
        Node right_node = query(2 * node + 1, mid + 1, r, ql, qr, O);
        
        return mergeNodes(left_node, right_node, O[mid]);
    }

public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int total_ones = 0;
        for (char c : s) {
            if (c == '1') total_ones++;
        }

        // Precompute all continuous 0-blocks globally
        vector<pair<int, int>> Z_blocks;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                int start = i;
                while (i + 1 < n && s[i + 1] == '0') i++;
                Z_blocks.push_back({start, i});
            }
        }

        int M = Z_blocks.size();
        vector<long long> Z(M);
        vector<long long> O(max(0, M - 1));

        for (int i = 0; i < M; i++) {
            Z[i] = Z_blocks[i].second - Z_blocks[i].first + 1;
        }
        for (int i = 0; i < M - 1; i++) {
            // The 1-block length is the gap between two 0-blocks
            O[i] = Z_blocks[i + 1].first - Z_blocks[i].second - 1;
        }

        if (M > 0) {
            tree.assign(4 * M, Node());
            build(1, 0, M - 1, Z, O);
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int L = q[0], R = q[1];
            
            // Binary search to find the bounding 0-blocks intersecting the query
            int a = -1, low = 0, high = M - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (Z_blocks[mid].second >= L) {
                    a = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            
            int b = -1;
            low = 0, high = M - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (Z_blocks[mid].first <= R) {
                    b = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            long long maxGain = 0;

            // If we have at least 2 zero-blocks inside the query, we can perform a trade
            if (a != -1 && b != -1 && a < b) {
                long long L_a = min((long long)R, (long long)Z_blocks[a].second) - max((long long)L, (long long)Z_blocks[a].first) + 1;
                long long L_b = min((long long)R, (long long)Z_blocks[b].second) - max((long long)L, (long long)Z_blocks[b].first) + 1;
                
                Node final_node;
                if (a + 1 == b) {
                    // Only 2 blocks, merge them manually
                    final_node = mergeNodes(Node(L_a), Node(L_b), O[a]);
                } else {
                    // Fetch inner blocks from Segment Tree, then attach modified edges
                    Node inner = query(1, 0, M - 1, a + 1, b - 1, O);
                    Node left_merge = mergeNodes(Node(L_a), inner, O[a]);
                    final_node = mergeNodes(left_merge, Node(L_b), O[b - 1]);
                }
                
                maxGain = max({final_node.maxA, final_node.maxLtoR, final_node.maxRtoL});
            }
            
            // Add the gain to the global total (outside '1's remain unchanged)
            ans.push_back(total_ones + maxGain);
        }

        return ans;
    }
};