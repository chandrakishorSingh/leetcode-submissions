Solution 1:
​
- If a number is a multiple of 25 then the last two digits of that number is either "00", "25", "50" or "75".
- So, we need to check whether any of these string exists in the given number string as subsequence or not. But we will only make that subsequence which has highest starting index to become the last two digits of the number. This is because we want to minimize the number of characters to be deleted.
- One corner case would be when the number string has only one 0. In this case, the given number is not a multiple of 25 but we can delete all other digits to make the number string 0 which is a multiple of 25.
​
```
class Solution {
private:
int isReverseSubsequenceExists(string subsequence, string& num) {
int i = 0;
for (auto it = num.rbegin(); it != num.rend(); it++) {
if (subsequence[i] == *it) {
i++;
if (i == subsequence.size()) {
return num.rend() - it - 1;
}
}
}
return -1;
}
public:
int minimumOperations(string num) {
int option1 = isReverseSubsequenceExists("00", num);
int option2 = isReverseSubsequenceExists("52", num);
int option3 = isReverseSubsequenceExists("05", num);
int option4 = isReverseSubsequenceExists("57", num);
int lastStartingIndex = max({option1, option2, option3, option4});
int candidate1 = num.size();
if (lastStartingIndex != -1) {
candidate1 = num.size() - lastStartingIndex - 2;
}
int candidate2 = num.size();
if (num.find('0') != string::npos && num.find_first_of('0') == num.find_last_of('0')) {
candidate2 = num.size() - 1;
}
return min(candidate1, candidate2);
}
};
​
// TC: O(n)
// SC: O(1)
```