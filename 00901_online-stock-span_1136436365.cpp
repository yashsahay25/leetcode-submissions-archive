class StockSpanner {
public:
    StockSpanner() {} // blank constructor
    stack<pair<int, int>> s; // store {price,count}

    // next function is called for each element of array
    int next(int price) {
        int count = 1;

        // number of elements popped will make the count
        while (!s.empty() && s.top().first <= price) {
            count += s.top().second;
            s.pop();
        }
        s.push({price, count});
        return count; // gives span for that price
    }
};

/**
 *Your StockSpanner object will be instantiated and called as such:
 *StockSpanner* obj = new StockSpanner();
 *int param_1 = obj->next(price);
 */