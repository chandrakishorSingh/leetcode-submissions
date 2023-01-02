NOTE:
​
- How computer performs division of two numbers ? Understand the algorithm and the circuit used to do it.
​
Solution 1(Brute-Force):
​
- Since the given number will be in the range of what an `int` data type can store, the range of largest number is fixed. Hence, we need to do the modulo operation at most 32 times.
​
```
class Solution {
public:
int countDigits(int num) {
int result = 0;
int originalNumber = num;
while (num != 0) {
int digit = num % 10;
if (digit != 0 and (originalNumber % digit == 0)) {
result++;
}
num /= 10;
}
return result;
}
};
​
// TC: O(1)
// SC: O(1)
```