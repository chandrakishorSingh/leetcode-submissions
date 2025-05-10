class Solution {
private:
    vector<int> getCoordinatesFromIndex(int index, int numberOfColumns) {
        int row = index / numberOfColumns;
        int col = index % numberOfColumns;
        
        return {row, col};
    }
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int low = 0;
        int high = (n * m) - 1;

        bool result = false;
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            
            vector<int> cell = getCoordinatesFromIndex(mid, m);
            int row = cell[0];
            int col = cell[1];
            
            if (matrix[row][col] > target) {
                high = mid - 1;
            } else if (matrix[row][col] < target) {
                low = mid + 1;
            } else {
                result = true;
                break;
            }
        }
        
        return result;
    }
};