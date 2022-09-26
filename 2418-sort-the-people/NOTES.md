Solution 1:
​
- Just create a structure(like `pair`) to associate every height with corresponding name. Sort according to the height and return the names.
​
```
class Solution {
public:
vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
int n = names.size();
vector<pair<int, string>> nameHeightPairArray(n);
for (int i = 0; i < n; i++)
nameHeightPairArray[i] = { heights[i], names[i] };
sort(nameHeightPairArray.rbegin(), nameHeightPairArray.rend());
vector<string> result(n);
for (int i = 0; i < n; i++)
result[i] = nameHeightPairArray[i].second;
return result;
}
};
​
// TC: O(n * log(n)) or TC of `sort()`
// SC: SC of `sort`, excluding the space required for output
```