class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n));
        
        queue<pair<int, int>> que;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    que.push({i, j});
                }
            }
        }
        
        int minutesElapsed = 0;
        while (!que.empty()) {
            int length = que.size();
            bool isFreshOrangesLeft = false;
            
            for (int i = 0; i < length; i++) {
                auto item = que.front();
                que.pop();

                int row = item.first;
                int col = item.second;

                vector<int> dx = {-1, 0, 1, 0};
                vector<int> dy = {0, 1, 0, -1};
                for (int pos = 0; pos < dx.size(); pos++) {
                    int newRow = row + dx[pos];
                    int newCol = col + dy[pos];

                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                        if (grid[newRow][newCol] == 1 && !visited[newRow][newCol]) {
                            que.push({newRow, newCol});
                            visited[newRow][newCol] = 1;
                            isFreshOrangesLeft = true;
                        }
                    }
                }
            }
            
            if (isFreshOrangesLeft) {
                minutesElapsed++;
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    return -1;
                }
            }
        }
        
        return minutesElapsed;
    }
};

// TC: O(m * n)
// SC: O(m * n)