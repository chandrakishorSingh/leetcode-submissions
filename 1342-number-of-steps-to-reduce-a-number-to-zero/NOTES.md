Solution 1:
​
- The number will become half of initial value after at most 2 steps.
​
```
class Solution {
public:
int numberOfSteps(int num) {
if (num == 0)
return 0;
return 1 + ((num & 1) ?  numberOfSteps(num - 1): numberOfSteps(num >> 1));
}
};
​
// TC: O(log(n))
// SC: O(log(n))
```
​
Solution 2:
​
- Iterative version of above solution
​
```
class Solution {
public:
int numberOfSteps(int num) {
int result = 0;
while (num != 0) {
num = (num & 1) ? num - 1: num >> 1;
result++;
}
return result;
}
};
​
// TC: O(log(n))
// SC: O(1)
```