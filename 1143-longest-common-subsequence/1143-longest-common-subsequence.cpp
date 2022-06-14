class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        
        vector<vector<int>> store(n1 + 1, vector<int>(n2 + 1, -1));
        
        return _longestCommonSubsequence(text1, text2, store, n1, n2);
    }
    
    int _longestCommonSubsequence(string& text1, string& text2, vector<vector<int>>& store, int index1, int index2) {
        if (store[index1][index2] != -1)
            return store[index1][index2];
        
        int result = -1;
        if (index1 == 0 || index2 == 0) {
            result = 0;
        } else {
            if (text1[index1 - 1] == text2[index2 - 1])
                result = 1 + _longestCommonSubsequence(text1, text2, store, index1 - 1, index2 - 1);
            else
                result = max(
                _longestCommonSubsequence(text1, text2, store, index1, index2 - 1),
                _longestCommonSubsequence(text1, text2, store, index1 - 1, index2)
            );
        }
        
        store[index1][index2] = result;
        
        return store[index1][index2];
    }
};