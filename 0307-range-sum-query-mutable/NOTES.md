TODO:
​
- Study sqrt decomposition
- study segment tree.
- Understand why the BIT building takes O(n) using that approach.
​
Solution 1(Brute-Force, TLE):
​
- Summing all elements in `[left, right]` for every call to `sumRange()`.
​
```
class NumArray {
public:
vector<int> nums;
NumArray(vector<int>& nums) {
this->nums = nums;
}
void update(int index, int val) {
this->nums[index] = val;
}
int sumRange(int left, int right) {
return accumulate(this->nums.begin() + left, this->nums.begin() + right + 1, 0);
}