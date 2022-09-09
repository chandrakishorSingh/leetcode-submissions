- Just find the longest length of subarray starting from current number and going backwards for which the numbers are less than or equal to the current number.
​
```
class StockSpanner {
public:
vector<int> prices;
StockSpanner() {}
int next(int price) {
int count = 1;
for (int i = prices.size() - 1; i >= 0 && price >= prices[i]; i--)
count++;
prices.push_back(price);
return count;
}
};
​
/**
* Your StockSpanner object will be instantiated and called as such:
* StockSpanner* obj = new StockSpanner();
* int param_1 = obj->next(price);
*/
​
// TC: O(i) for the ith call to next()
// SC: O(i) for the ith call to next()
```