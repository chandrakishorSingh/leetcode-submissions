return result == -1 ? "" : string(3, ('0' + result));
}
};
​
// TC: O(n)
// SC: O(1)
```
​
Solution 2:
​
- Same as 1st one but uses one less variable :P
​
```
class Solution {
public:
string largestGoodInteger(string num) {
int count = 1;
int result = -1;
for (int i = 1; i < num.size(); i++) {
if (num[i] == num[i - 1]) {
count++;
if (count == 3) {
result = max(result, num[i] - '0');
count = 0;
}
} else {
count = 1;
}
}
return result == -1 ? "" : string(3, ('0' + result));
}
};
​
// TC: O(n)
// SC: O(1)
```