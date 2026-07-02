class StockSpanner {
public:
    stack<pair<int, int>> st;

    StockSpanner() { }
    
    int next(int price) {
        int newSpan = 1;

        while(!st.empty() && price >= st.top().first) {
            int lastTop = st.top().first;
            int lastSpan = st.top().second;
            st.pop();
            newSpan += lastSpan;
        }

        st.push({price, newSpan});
        return newSpan;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */