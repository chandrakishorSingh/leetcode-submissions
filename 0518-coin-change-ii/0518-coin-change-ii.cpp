class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> current(amount + 1);
        current[0] = 1;
        
        // vector<int> next = current;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (j >= coins[i - 1]) {
                    current[j] = current[j] + current[j - coins[i - 1]];
                    // cout << "Adding " << current[j] << " and " << next[j - coins[i - 1]] << endl;
                }
            }
            
            // current = next;
            // cout << i << ' ';
            // for (auto it: current) {
            //     cout << it << ' ';
            // }
            // cout << endl;
        }
        
        return current[amount];
    }
};

// TC: O(amount * n)
// SC: O(amount * n)