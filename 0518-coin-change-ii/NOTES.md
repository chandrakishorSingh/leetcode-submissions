for (int i = 1; i <= n; i++) {
for (int j = 1; j <= amount; j++) {
if (j >= coins[i - 1]) {
store[i][j] = store[i - 1][j] + store[i][j - coins[i - 1]];
} else {
store[i][j] = store[i - 1][j];
}
}
}
return store[n][amount];
}
};
​
// TC: O(amount * n)
// SC: O(amount * n)
```
​
Solution 4:
​
- Space optimized Bottom-up DP.
​
```
class Solution {
public:
int change(int amount, vector<int>& coins) {
int n = coins.size();
vector<int> current(amount + 1);
current[0] = 1;
for (int i = 1; i <= n; i++) {
for (int j = 1; j <= amount; j++) {
if (j >= coins[i - 1]) {
current[j] = current[j] + current[j - coins[i - 1]];
}
}
}
return current[amount];
}
};
​
// TC: O(amount * n)
// SC: O(amount)
```
​