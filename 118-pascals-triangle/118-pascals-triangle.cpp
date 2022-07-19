class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result = {{1}, {1, 1}};

        if (numRows <= 2)
            return vector<vector<int>>(result.begin(), result.begin() + numRows);
        
        for (int i = 3; i <= numRows; i++) {
            vector<int> currentRow({1});
            for (int j = 1; j < result.back().size(); j++)
                currentRow.push_back(result[i - 2][j] + result[i - 2][j - 1]);
            
            currentRow.push_back(1);

            result.push_back(currentRow);
        }
        
        return result;
    }
};