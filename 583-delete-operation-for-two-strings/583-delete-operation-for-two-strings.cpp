class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        
        vector<vector<int>> store(n1 + 1, vector<int>(n2 + 1, -1));
        
        int lcs = _longestCommonSubsequence(word1, word2, store, n1, n2);
        
        return n1 + n2 - 2 * lcs;
    }
    
    int _longestCommonSubsequence(string& word1, string& word2, vector<vector<int>>& store, int index1, int index2) {
        if (store[index1][index2] != -1)
            return store[index1][index2];
        
        int result = -1;
        if (index1 == 0 || index2 == 0) {
            result = 0;
        } else {
            if (word1[index1 - 1] == word2[index2 - 1])
                result = 1 + _longestCommonSubsequence(word1, word2, store, index1 - 1, index2 - 1);
            else
                result = max(
                _longestCommonSubsequence(word1, word2, store, index1, index2 - 1),
                _longestCommonSubsequence(word1, word2, store, index1 - 1, index2)
            );
        }
        
        store[index1][index2] = result;
        
        return store[index1][index2];
    }
};