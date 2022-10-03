TODO:
​
- easy implementation: https://leetcode.com/problems/longest-uploaded-prefix/discuss/2646696/Python-Elegant-and-Short-or-Amortized-O(1)-or-Commented
- good one: easy to understand and implement and efficient(amortized constant) : https://leetcode.com/problems/longest-uploaded-prefix/discuss/2646553/C%2B%2B-with-Explanation-oror-Very-Simple-and-Easy-to-Understand-Solution
​
Solution 1(Brute-Force, TLE):
​
- Just do the simulation.
​
```
class LUPrefix {
public:
vector<int> arr;
LUPrefix(int n) {
this->arr.resize(n);
}
void upload(int video) {
arr[video - 1] = 1;
}
int longest() {
int result = 0;