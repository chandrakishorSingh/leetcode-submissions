Solution 1:
​
- It's easy to see that it's a sliding window problem.
- If arr[i:j] exceeds the budget then so does arr[i:j+k] where k > 0. In such case we should start from i + 1. But we don't have to "start over" as we can use the "values" calculated for arr[i:j] to find "values" for arr[i+1:].
- The only thing to figure out was an efficient way to calculate the maximum of subarray as it's growing from it's right end and shrinking from left end. This can be efficiently achieved using a maximum queue.
​
```
class MaxStack {
public:
int max() {
return st.top().second;
}
void push(int num) {
if (st.empty())
st.push({ num, num });
else
st.push({ num, std::max(this->max(), num) });
}
void pop() {
st.pop();
}
int top() {
return st.top().first;
}
int size() {
return st.size();
}
bool empty() {