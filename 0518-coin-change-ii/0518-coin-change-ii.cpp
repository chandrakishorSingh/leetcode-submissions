class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> store(n + 1, vector<int>(amount + 1));
        
        for (int i = 0; i <= n; i++) {
            store[i][0] = 1;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (j >= coins[i - 1]) {
                    store[i][j] = store[i - 1][j] + store[i][j - coins[i - 1]];
                } else {
                    store[i][j] = store[i - 1][j];
                }
            }
        }
        
        return store[n][amount];
    }
};

// TC: O(amount * n)
// SC: O(amount * n)