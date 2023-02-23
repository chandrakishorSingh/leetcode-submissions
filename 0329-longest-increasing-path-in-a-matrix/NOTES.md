}
longestIncreasingPathLength = max(longestIncreasingPathLength, dp[newRow][newCol]);
}
dp[row][col] = longestIncreasingPathLength + 1;
result = max(result, dp[row][col]);
}
return result;
}
};
​
// TC: O(n * m * log(n * m))
// SC: O(n * m)
```
​
​
​
​
​
​
​
​
​
​