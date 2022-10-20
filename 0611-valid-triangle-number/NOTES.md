public:
int triangleNumber(vector<int>& nums) {
sort(nums.begin(), nums.end());
int result = 0;
for (int i = 0; i < nums.size(); i++) {
int k = i + 2;
for (int j = i + 1; j < nums.size(); j++) {
k = max(k, j + 1);
while ((k < nums.size()) && (nums[i] + nums[j] > nums[k])) {
k++;
}
result += k - j - 1;
}
}
return result;
}
};
​
// TC: O(n^2)
// SC: O(log(n)) for sorting
```
​
​