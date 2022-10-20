if (left <= nums.begin() + i && count > 0)
count--;
result += count;
}
}
return result / 3;
}
};
​
// TC: O(n^2 * log(n))
// SC: SC of lower_bound() + upper_bound() + sort() or O(log(n))
```
​
Soluion 3:
​
- Simple implementation of the 2nd approach.
- We can restrict the array length over which we find the third element. This way we don't end up counting the same triplets again.
- We'll only search in the subarray [j + 1, n] when we've fixed the pair (i, j) as two sides.
​
```
class Solution {
public:
int triangleNumber(vector<int>& nums) {
sort(nums.begin(), nums.end());
int n = nums.size();
int result = 0;
for (int i = 0; i < n; i++) {
for (int j = i + 1; j < n; j++) {
auto k = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]) - nums.begin();
result += k - j - 1;
}
}
return result;
}
};
​
// TC: O(n^2 * log(n))
// SC: O(log(n)), usually sorting algo. uses log(n) of recursive stack space
```