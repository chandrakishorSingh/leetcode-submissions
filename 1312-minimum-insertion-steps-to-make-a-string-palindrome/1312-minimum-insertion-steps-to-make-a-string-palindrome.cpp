class Solution {
private:
    int _lcs(string& text1, string& text2) {
        if (text1.size() < text2.size()) {
            return _lcs(text2, text1);
        }
        
        int n1 = text1.size();
        int n2 = text2.size();
        
        vector<int> store(n2 + 1);
        
        for (int i = 1; i <= n1; i++) {
            int previousState = store[0];
            
            for (int j = 1; j <= n2; j++) {
                int currentState = text1[i - 1] == text2[j - 1] ? 1 + previousState : max(store[j], store[j - 1]);
                
                previousState = store[j];
                store[j] = currentState;
            }
        }
        
        return store[n2];

    }
    
public:
    int minInsertions(string s) {
        string r = string(s.rbegin(), s.rend());
        
        return s.size() - _lcs(s, r);
    }
};