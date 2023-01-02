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
        vector<int> nums(upperLimit + 1);
        
        for (int i = 2; i <= upperLimit; i++) {
            for (int j = 2 * i; j <= upperLimit; j += i) {
                nums[j] = 1;
            }
        }
        
        vector<int> result;
        for (int i = 2; i <= upperLimit; i++) {
            if (i >= lowerLimit and nums[i] != 1) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};