Solution 1:
​
- Every row can be associated with a binary string or equivalent decimal number.
- We will store all of these numbers and their corresponding frequency.
- Then we will find all of the numbers that can be generated using `cols` number of set bits and `n - cols` number of 0s. Then for each of those numbers we will find how many of rows can be "covered".
​
```
class Solution {
public:
int maximumRows(vector<vector<int>>& mat, int cols) {
int m = mat.size();
int n = mat[0].size();
unordered_map<int, int> rowBitPatternFreq;
for (int i = 0; i < m; i++) {
int key = 0;
for (int j = 0; j < n; j++) {
key = (key << 1) + mat[i][j];
}
rowBitPatternFreq[key]++;
}
int result = 0;
for (int i = 0; i < (1 << n); i++) {
if (__builtin_popcount(i) != cols)
continue;
int count = 0;
for (auto it = rowBitPatternFreq.begin(); it != rowBitPatternFreq.end(); it++) {
if (isCovers(i, it->first))
count += it->second;
}
result = max(result, count);
}
return result;
}
bool isCovers(int num1, int num2) {
return (num1 | num2) == num1;
}
};
​
// TC: O(m * n + (2^n) * m)
// SC: O(m)
```