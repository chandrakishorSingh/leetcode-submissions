class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> queenPositions;
        
        backtrack(0, n, queenPositions, result);
        
        return result;
    }
    
    void backtrack(int row, int n, vector<int>& queenPositions, vector<vector<string>>& result) {
        if (row == n) {
            auto board = createBoard(n, queenPositions);
            result.push_back(board);

            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (canPlace(i, queenPositions)) {
                queenPositions.push_back(i);
                
                backtrack(row + 1, n, queenPositions, result); 
                
                queenPositions.pop_back();
            }
        }
    }
    
    bool canPlace(int currentPosition, vector<int>& queenPositions) {
        int size = queenPositions.size();
        
        for (int i = 0; i < size; i++) {
            if (
                (queenPositions[size - i - 1] == currentPosition) ||
                (queenPositions[size - i - 1] == currentPosition - i - 1) ||
                (queenPositions[size - i - 1] == currentPosition + i + 1)
               )
                return false;
        }
        
        return true;
    }
    
    vector<string> createBoard(int n, vector<int>& queenPositions) {
        vector<string> result;
        
        for (auto position: queenPositions) {
            string row = string(n, '.');
            row[position] = 'Q';
            result.push_back(row);
        }
        
        return result;
    }
};