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
};
​
// TC:
// NumArray(): O(n)
// sumRange(): O(right - left)
// update(): O(1)
// SC:
// NumArray(): O(n)
// sumRange(): O(1)
// update(): O(1)
​
/**
* Your NumArray object will be instantiated and called as such:
* NumArray* obj = new NumArray(nums);
* obj->update(index,val);
* int param_2 = obj->sumRange(left,right);
*/
```