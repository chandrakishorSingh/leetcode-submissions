Solution 1(Brute-Force, TLE):
​
- Just check all possible submatrices.
​
```
class Solution {
public:
int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
int m = matrix.size();
int n = matrix[0].size();
int result = 0;
for (int xi = 0; xi < m; xi++)
for (int yi = 0; yi < n; yi++)
for (int xj = xi; xj < m; xj++)
for (int yj = yi; yj < n; yj++)
if (matrixSum(matrix, xi, yi, xj, yj) == target)
result++;
return result;
}
int matrixSum(vector<vector<int>>& matrix, int xi, int yi, int xj, int yj) {
int64_t sum = 0;
for (int i = xi; i <= xj; i++)
for (int j = yi; j <= yj; j++)
sum += matrix[i][j];
return sum;
}
};
​
// TC: O((m * n)^3)
// SC: O(1)
```