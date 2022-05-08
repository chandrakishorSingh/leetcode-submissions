Solution 1:
​
- Answer will always be from "111", "222", ... "999", "".
- Just check whether a digit is repeated thrice consecutively.
- Pick the largest such digit
​
```
class Solution {
public:
string largestGoodInteger(string num) {
int count = 1;
char digit = num[0];
int result = -1;
for (int i = 1; i < num.size(); i++) {
if (num[i] == digit) {
count++;
if (count == 3) {
result = max(result, digit - '0');
count = 0;
}
} else {
digit = num[i];
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