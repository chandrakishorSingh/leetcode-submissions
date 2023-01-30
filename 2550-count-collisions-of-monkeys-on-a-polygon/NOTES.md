Solution 1(TLE):
​
- Since every monkey has to jump one step in either clockwise or anticlockwise direction, every monkey has 2 choices.
- It's easy to see that there will be a total of 2^n different configurations of the jump sequence by all of the monkeys. And only 2 of those will result in no collision at all(when all monkeys jump in either clockwise or anticlockwise direction). So, total number of ways by which monkeys can move so that at least one collision happens is 2^n - 2.
- So, it can be done in linear time.
​
```
class Solution {
public:
int monkeyMove(int n) {
int64_t mod = 1e9 + 7;
int64_t result = 1;
for (int i = 0; i < n; i++) {
result = (result * (int64_t)2) % mod;
}
result -= 2;
if (result <= 0) {
result += mod;
}
return result;
}
};
// TC: O(n)
// SC: O(1)
```
​
Solution 2:
​
- Since we're getting TLE, we need to use binary exponentiation(or fast exponentiation).
​
```
class Solution {
public:
int monkeyMove(int n) {
int mod = 1e9 + 7;
auto result = power(2, n, mod) - 2;