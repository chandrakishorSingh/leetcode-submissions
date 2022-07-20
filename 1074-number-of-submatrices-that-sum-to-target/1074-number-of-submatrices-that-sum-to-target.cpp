class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + matrix[i - 1][j - 1];
        
        unordered_map<int, int> prefixSumFreq;
        
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = i; j < m; j++) {
                prefixSumFreq.clear();
                prefixSumFreq[0] = 1;
                
                for (int k = 0; k < n; k++) {
                    int cumulativeSum = prefixSum[j + 1][k + 1] - prefixSum[i][k + 1] - prefixSum[j + 1][0] + prefixSum[i][0];
                    
                    auto it = prefixSumFreq.find(cumulativeSum - target);
                    if (it != prefixSumFreq.end()) {
                        result += it->second;
                    }
                    
                    prefixSumFreq[cumulativeSum]++;
                }
            }
        }
        
        return result;
    }
};