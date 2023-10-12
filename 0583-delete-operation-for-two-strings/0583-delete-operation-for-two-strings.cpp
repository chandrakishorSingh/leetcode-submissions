class Solution {
private:
    int lcs(string& str1, string& str2) {
        if (str2.size() > str1.size()) {
            return lcs(str2, str1);
        }
        
        int n1 = str1.size();
        int n2 = str2.size();
        vector<int> store(n2 + 1);

        for (int i = 1; i <= n1; i++) {
            int previous = store[0];
            
            for (int j = 1; j <= n2; j++) {
                int current = str1[i - 1] == str2[j - 1] ? 1 + previous : max(store[j - 1], store[j]);
                
                previous = store[j];
                store[j] = current;
            }
        }
        
        return store[n2];
    }

public:
    int minDistance(string word1, string word2) {
        return word1.size() + word2.size() - 2 * lcs(word1, word2);
    }
};