class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for (int size = n, index = 0; size >= 1; size -= 2, index++) {
            for (int j = 0; j < size - 1; j++) {
                int newRow = index;
                int newCol = index + j;

                int oldCellValue = matrix[newRow][newCol];
                int newCellValue = oldCellValue;

                int count = 4;
                while (count--) {
                    vector<int> nextPos = nextCellPos(newRow, newCol, n);
                    newRow = nextPos[0];
                    newCol = nextPos[1];
                    
                    newCellValue = matrix[newRow][newCol];
                    matrix[newRow][newCol] = oldCellValue;
                    oldCellValue = newCellValue;

                }
            }
        }
    }
    
    vector<int> nextCellPos(int row, int col, int size) {
        return {col, size - row - 1};
    }
};
