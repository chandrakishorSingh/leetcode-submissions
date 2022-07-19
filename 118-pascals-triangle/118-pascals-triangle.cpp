class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result = {{1}};

        for (int i = 2; i <= numRows; i++) {
            vector<int> currentRow({1});
            for (int j = 1; j < result.back().size(); j++)
                currentRow.push_back(result[i - 2][j] + result[i - 2][j - 1]);
            
            currentRow.push_back(1);

            result.push_back(currentRow);
        }
        
        return result;
    }
};

// TC: O(n^2)
// SC: O(1), except the output