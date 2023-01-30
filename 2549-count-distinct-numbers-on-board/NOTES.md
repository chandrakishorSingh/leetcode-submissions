Solution 1:
​
- Observe that after each iteration the number x - 1 appears in the board if the number x was already present in the board.
- And since the range of the values of n is <= 100 and the number of iteration is 10^9. All numbers from 1 to x - 1 will be present after x - 1 iteration.
​
```
class Solution {
public:
int distinctIntegers(int n) {
return n == 1 ? 1 : n - 1;
}
};
​
// TC: O(1)
// SC: O(1)
```