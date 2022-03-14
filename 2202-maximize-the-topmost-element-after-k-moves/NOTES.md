Solution 1:
​
- Only elements that are in the range of index `0 - k` may participate in determining the maximum possible top element. Though it is easy to see that it is not sufficient criteria.
- We will iterate on all such indices and ask "Is there is some sequence of moves by which this index will be at the top ?"
- We will require `i` "pop" operations to reach the element at index `i`. Then we are left with `r = k - i` moves.
- If `r` is even then we can just do pop-push successively on this element. Hence it could be the result.
- If `r` is 1 then there is no way for this index to be the result.
- For all other `r`(odd numbers > 1), if we have at least one element in the right of `i` or at least one element in the left of `i` then we can find a sequence of moves to make this index to be at the top(it is easy to find such sequence for `r = 3` and for other odd numbers, induction can be used).
- Though, this is obviously not an exhaustive proof as I haven't shown that there is no move sequence when an index is not selected according to the stated mechanism.
​
```
class Solution {
public:
int maximumTop(vector<int>& nums, int k) {
int n = nums.size();
int result = -1;
for (int i = 0; i < min(k + 1, n); i++) {
if ((k - i) % 2 == 0)
result = max(result, nums[i]);
else if (k - i == 1)
continue;
else if (i > 0 || i != n - 1)
result = max(result, nums[i]);
}
return result;
}
};
​
// TC: O(n)
// SC: O(1)
```
​
Solution 2;
​
Try to understand this https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/discuss/1845511/C%2B%2B-or-Short-and-Crisp-Code-or-Greedy-Approach-or-Linear-time-and-Constant-space