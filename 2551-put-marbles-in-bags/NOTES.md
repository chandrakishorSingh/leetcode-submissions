Solution 1:
​
- Observe that there are only n - 1 "cuts" possible in an array of size n.
- And out of those n - 1 "cuts", we need to choose exactly k - 1 "cuts" twice. First when we want to maximize the score of distribution and the second time when we want to minimize the score of distribution. So, how to choose the appropriate "cuts" ?
- Note that when we choose a cut, we choose the left end of one bag and right end of another. Hence, the weights at these two position will be added to find the score of distribution. So, every cut has a "contribution" which is equal to sum of weights at that cut.
- Hence, to maximize the score, we need to choose the cuts in decreasing order of their contribution and to minimize the score we need to choose them in their increasing order of contribution.
- This can be done by two priority queues(one minimum and one maximum priority queue).
​
```
class Solution {
public:
typedef long long ll;
long long putMarbles(vector<int>& weights, int k) {
priority_queue<int> maxPQ;
priority_queue<int, vector<int>, greater<int>> minPQ;
for (int i = 0; i < weights.size() - 1; i++) {
int value = weights[i] + weights[i + 1];
maxPQ.push(value);
minPQ.push(value);
}
ll result = 0;
while (k > 1) {
result += maxPQ.top() - minPQ.top();
maxPQ.pop();
minPQ.pop();
k--;
}
return result;
}
};
​
// TC: O(n * log(n))
// SC: O(n)
```
​
​