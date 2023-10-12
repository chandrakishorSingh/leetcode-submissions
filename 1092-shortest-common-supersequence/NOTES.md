}
public:
string shortestCommonSupersequence(string str1, string str2) {
string longestCommonSubsequence = lcs(str1, str2);
int i = 0;
int j = 0;
string result = "";
for (int k = 0; k < longestCommonSubsequence.size(); k++) {
while (str1[i] != longestCommonSubsequence[k]) {
result += str1[i];
i++;
}
while (str2[j] != longestCommonSubsequence[k]) {
result += str2[j];
j++;
}
result += longestCommonSubsequence[k];
i++;
j++;
if (k == longestCommonSubsequence.size() - 1) {
while (i < str1.size()) {
result += str1[i];
i++;
}
while (j < str2.size()) {
result += str2[j];
j++;
}
}
}
return result;
}
};
​
// TC: O(len(str1) * len(str2))
// SC: O(len(str1) * len(str2))
```