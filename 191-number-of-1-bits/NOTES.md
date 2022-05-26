Solution 1:
​
- Using `__builtin_popcount()`
- Note that technically, the complexity of this function is linear over the number of bits.
​
```
class Solution {
public:
int hammingWeight(uint32_t n) {
return __builtin_popcount(n);
}
};
// TC: O(1)
// SC: O(1)
```