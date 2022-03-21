class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        vector<vector<int>> store(numCarpets + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= n; i++)
            store[0][i] = store[0][i - 1] + (floor[i - 1] == '1');
        
        for (int i = 1; i <= numCarpets; i++) {
            for (int j = 1; j <= n; j++) {
                store[i][j] = min(
                    j - carpetLen < 0 ? 0: store[i - 1][j - carpetLen],
                    store[i][j - 1] + (floor[j - 1] == '1')
                );
            }
        }
        
        return store[numCarpets][n];
    }
};

// TC: O(length of floor str * numCarpets)
// SC: O(length of floor str * numCarpets)