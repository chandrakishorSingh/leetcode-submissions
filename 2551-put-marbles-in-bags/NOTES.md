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
- Another similar implementation of this would be to use an array to store contributions. We thenneed to sort the array to find the appropriate cuts.
​
```
class Solution {
public:
typedef long long ll;
long long putMarbles(vector<int>& weights, int k) {
int n = weights.size();
vector<int> contributions(n - 1);
for (int i = 0; i < n - 1; i++) {
contributions[i] = weights[i] + weights[i + 1];
}
sort(contributions.begin(), contributions.end());
ll result = 0;
for (int i = 0; i < k - 1; i++) {
result += contributions[n - 2 - i] - contributions[i];
}
return result;
}
};
​
// TC: O(n * log(n))
// SC: O(n)
```