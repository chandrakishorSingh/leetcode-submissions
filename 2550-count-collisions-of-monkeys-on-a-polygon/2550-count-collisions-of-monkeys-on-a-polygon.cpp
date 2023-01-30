class Solution {
public:
    int monkeyMove(int n) {
        int mod = 1e9 + 7;
        auto result = power(2, n, mod) - 2;
        
        return result <= 0 ? result + mod : result;
    }
    
    int power(int base, int index, int mod) {
        if (index == 0)
            return 1;
        
        int result = power(base, index / 2, mod);
        
        result = ((int64_t)result * result) % mod;
        
        if (index % 2 != 0) {
            result = ((int64_t)result * base) % mod;
        }
        
        return result;
    }
};

// TC: O(log(n))
// SC: O(log(n))
