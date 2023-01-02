Solution 1:
​
- Simple idea.
- Find all prime numbers between `left` and `right`. Find a pair of consecutive prime numbers whose difference is minimum.
​
```
class Solution {
public:
vector<int> closestPrimes(int left, int right) {
vector<int> primes = getPrimeNumbers(left, right);
if (primes.size() < 2) {
return {-1, -1};
}
int num1 = primes[0];
int num2 = primes[1];
int minDifference = num2 - num1;
for (int i = 2; i < primes.size(); i++) {
if (primes[i] - primes[i - 1] < minDifference) {
num1 = primes[i - 1];
num2 = primes[i];
minDifference = num2 - num1;
}
}
return { num1, num2 };
}
vector<int> getPrimeNumbers(int lowerLimit, int upperLimit) {
vector<int> result;