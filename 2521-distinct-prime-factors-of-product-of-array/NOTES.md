}
}
vector<int> result;
for (int i = 2; i <= upperLimit; i++) {
if (nums[i] != 1) {
result.push_back(i);
}
}
return result;
}
};
​
// TC: O(n^2)
// SC: O(n)
```
​
Solution 3:
​
- Straightforward idea.
- For every number, find all prime factors and insert them into a global set.
- I know its TC but It's difficult to write in terms of size of array or the array elements.
​
```
class Solution {
public:
int distinctPrimeFactors(vector<int>& nums) {
set<int> primes;
for (auto num: nums) {
int divisor = 2;
while (num != 1) {
bool flag = false;
while (num % divisor == 0) {
num /= divisor;
flag = true;
}
if (flag) {
primes.insert(divisor);
}
divisor++;
}
}
return primes.size();
}
};
```