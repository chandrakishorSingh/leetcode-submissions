int right = str.size() - 1;
while (left < right) {
if (str[left] != str[right])
return false;
left++;
right--;
}
return true;
}
};
​
// TC: O(n * log(n))
// SC: O(log(n))
```
​
​
Solution 2:
​
- It's not hard to see that not many numbers will be able to satisfy this condition.
- And actually it can be proved that for n >= 4, there is no number which satisfies this condition. Below is a proof taken from [here](https://leetcode.com/problems/strictly-palindromic-number/discuss/2524702/return-false)
​
Prove
4 = 100 (base 2), so 4 is not strictly palindromic number
for n > 4, consider the base n - 2.
In base n - 1, n = 11.
In base n - 2, n = 12, so n is not strictly palindromic number.
​
There is no strictly palindromic number n where n >= 4
​
```
class Solution {
public:
bool isStrictlyPalindromic(int n) {
return false;
}
};
​
// TC: O(1)
// SC: O(1)
```