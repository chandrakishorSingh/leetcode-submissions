class Solution {
public:
    typedef vector<int> item;
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        priority_queue<item> pq;
        
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                pq.push({ matrix[i][j], i, j });
        
        int result = -1;
        vector<vector<int>> dp(n, vector<int>(m));
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            int row = top[1];
            int col = top[2];
            vector<int> dx = {-1, 0, 1, 0};
            vector<int> dy = {0, 1, 0, -1};
            
            int longestIncreasingPathLength = 0;
            for (int i = 0; i < dx.size(); i++) {
                int newRow = row + dx[i];
                int newCol = col + dy[i];
                
                if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m || matrix[newRow][newCol] <= matrix[row][col]) {
                    continue;
                }
                
                longestIncreasingPathLength = max(longestIncreasingPathLength, dp[newRow][newCol]);
            }
            
            dp[row][col] = longestIncreasingPathLength + 1;
            
            result = max(result, dp[row][col]);
        }
        
        // for (auto row: dp) {
        //     for (auto col : row) {
        //         cout << col << " ";
        //     }
        //     cout << endl;
        // }
        
        return result;
    }
};