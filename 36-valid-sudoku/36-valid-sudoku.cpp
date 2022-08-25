class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.')
                    continue;
                
                auto rowEntry = "r" + to_string(i) + to_string(board[i][j]);
                auto colEntry = "c" + to_string(j) + to_string(board[i][j]);
                auto blockEntry = "b" + to_string(i / 3) + to_string(j / 3) + to_string(board[i][j]);
                
                if (st.count(rowEntry) || st.count(colEntry) || st.count(blockEntry))
                    return false;
                
                st.insert(rowEntry);
                st.insert(colEntry);
                st.insert(blockEntry);
            }
        }
        
        return true;
    }
};