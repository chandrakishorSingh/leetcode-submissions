class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int it1 = 0;
        int it2 = 0;
        
        string result = "";
        for (; it1 < word1.size() && it2 < word2.size(); it1++, it2++) {
            result.push_back(word1[it1]);
            result.push_back(word2[it2]);
        }
        
        while (it1 < word1.size()) {
            result.push_back(word1[it1]);
            it1++;
        }
        
        while (it2 < word2.size()) {
            result.push_back(word2[it2]);
            it2++;
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(1), except output