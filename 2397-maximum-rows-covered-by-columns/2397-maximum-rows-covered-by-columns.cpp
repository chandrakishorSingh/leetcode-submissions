class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int m = mat.size();
        int n = mat[0].size();
        
        unordered_map<int, int> rowBitPatternFreq;
        for (int i = 0; i < m; i++) {
            int key = 0;
            for (int j = 0; j < n; j++) {
                key = (key << 1) + mat[i][j];
            }
            
            rowBitPatternFreq[key]++;
        }
        
        int result = 0;
        for (int i = 0; i < (1 << n); i++) {
            if (__builtin_popcount(i) != cols)
                continue;
            
            int count = 0;
            for (auto it = rowBitPatternFreq.begin(); it != rowBitPatternFreq.end(); it++) {
                if (isCovers(i, it->first))
                    count += it->second;
            }
            
            result = max(result, count);
        }
        
        return result;
    }
    
    bool isCovers(int num1, int num2) {
        return (num1 | num2) == num1;
    }
};

// TC: O()
// SC: O()