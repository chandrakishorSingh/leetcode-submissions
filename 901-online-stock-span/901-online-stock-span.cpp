class StockSpanner {
public:
    stack<pair<int, int>> priceSpan;
    
    StockSpanner() {}
    
    int next(int price) {
        int spanLength = 1;
        while (!priceSpan.empty() && priceSpan.top().first <= price) {
            spanLength += priceSpan.top().second;
            priceSpan.pop();
        }
        
        priceSpan.push({ price, spanLength });
        
        return spanLength;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */