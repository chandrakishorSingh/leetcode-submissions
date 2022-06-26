class Solution {
public:
    int countHousePlacements(int n) {
        int mod = 1e9 + 7;
        
        vector<int64_t> store(n + 1);
        store[0] = 1;
        store[1] = 2;
        
        for (int i = 2; i <= n; i++)
            store[i] = ((store[i - 1] % mod) + (store[i - 2] % mod) % mod);
        
        return ((store[n] % mod) * (store[n] % mod)) % mod;
    }
};