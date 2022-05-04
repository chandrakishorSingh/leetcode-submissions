Solution 1:
​
- Eliminate the search space.
- Initially it's from `start = 0, end = n-1`
- If sum of elements at these positions is greater than target then element at end can't be part of the solution.
- On the other hand, if sum is less than target then element at start can't be part of the solution.
- Thus we can successively eliminate the search space and can arrive at the solution(as it is guaranteed to be present here)
​
```
class Solution {
public:
vector<int> twoSum(vector<int>& numbers, int target) {
int start = 0;
int end = numbers.size() - 1;
while (start <= end) {
int sum = numbers[start] + numbers[end];
if (sum == target)
break;
else if (sum > target)
end--;
else
start++;
}
return {start + 1, end + 1};
}
};
​
// TC: O(n)
// SC: O(1)
```