struct Node {
    int ml;
    int pl;
    int sl;
    char pc;
    char sc;
    int sz;
};

class Solution {
    vector<Node> tree;
    string str;

    Node merge(Node l, Node r) {
        Node cur;
        cur.sz = l.sz + r.sz;
        cur.pc = l.pc;
        cur.sc = r.sc;
        
        cur.pl = l.pl;
        if (l.pl == l.sz && l.pc == r.pc) {
            cur.pl += r.pl;
        }
        
        cur.sl = r.sl;
        if (r.sl == r.sz && r.sc == l.sc) {
            cur.sl += l.sl;
        }
        
        cur.ml = max(l.ml, r.ml);
        if (l.sc == r.pc) {
            cur.ml = max(cur.ml, l.sl + r.pl);
        }
        
        return cur;
    }

    void build(int node, int st, int en) {
        if (st == en) {
            tree[node].ml = 1;
            tree[node].pl = 1;
            tree[node].sl = 1;
            tree[node].pc = str[st];
            tree[node].sc = str[st];
            tree[node].sz = 1;
            return;
        }
        int mid = st + (en - st) / 2;
        build(2 * node, st, mid);
        build(2 * node + 1, mid + 1, en);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int st, int en, int idx, char val) {
        if (st == en) {
            str[idx] = val;
            tree[node].pc = val;
            tree[node].sc = val;
            return;
        }
        int mid = st + (en - st) / 2;
        if (st <= idx && idx <= mid) {
            update(2 * node, st, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, en, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        str = s;
        tree.resize(4 * n);
        build(1, 0, n - 1);
        
        int k = queryIndices.size();
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].ml;
        }
        return ans;
    }
};