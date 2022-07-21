bool result = false;
​
subSequence.push_back(t[index]);
result |= dfs(s, t, subSequence, index + 1);
if (result)
return result;
subSequence.pop_back();
result |= dfs(s, t, subSequence, index + 1);
return result;
}
};
​
// TC: O(2^n * n)
// SC: O(n)
// n = length of t
```
​
Solution 2:
​
- Observations
-