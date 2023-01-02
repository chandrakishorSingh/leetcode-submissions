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

// TC: O(n^2)
// SC: O(n)