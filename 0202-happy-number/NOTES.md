NOTE:
​
- It would be interesting to know the proof of this fact.
​
Solution 1(Brute-Force)
​
- It's given that every number either ends up in 1 or goes through a circular sequence of numbers under this operation.
- Hence, we can just store these numbers and check whether the next number is someone which we have seen so far or not. If at any point in time the next number is 1 then it's confirmed that the number is a happy number.
- A rough estimate of time and space complexity of this algorithm can be said to be constant because the range of input is limited(integer range limit) and the number of states will be a finite number in case the number is not a happy number.
​
```
class Solution {
public:
bool isHappy(int n) {
vector<int> squares = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
unordered_set<int> states;
int currentState = n;
while (true) {
if (states.count(currentState))
return false;
if (currentState == 1)
break;