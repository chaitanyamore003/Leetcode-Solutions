class StockSpanner {
private:
    stack<pair<int, int>> spans;

public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;

        while (!spans.empty() && spans.top().first <= price) {
            span += spans.top().second;
            spans.pop();
        }
        spans.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */