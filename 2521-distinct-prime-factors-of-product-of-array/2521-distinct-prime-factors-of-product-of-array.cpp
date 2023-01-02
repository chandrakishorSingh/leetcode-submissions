class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        vector<int> primes = getPrimeNumbers(1000);
        
        set<int> seen;
        for (auto num: nums) {
            for (int i = 0; i < primes.size() and num != 0; i++) {
                bool flag = false;
                
                while (num % primes[i] == 0) {
                    num /= primes[i];
                    flag = true;
                }
                
                if (flag) {
                    seen.insert(primes[i]);
                }
            }
        }
        
        return seen.size();
    }
    
    vector<int> getPrimeNumbers(int upperLimit) {
        vector<int> nums(upperLimit + 1);
        
        for (int i = 2; i <= upperLimit; i++) {
            if (nums[i]) {
                continue;
            }
            
            for (int j = 2 * i; j <= upperLimit; j += i) {
                nums[j] = 1;
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