class Solution {
private:
    string lcs(string& str1, string& str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        
        vector<vector<int>> store(n1 + 1, vector<int>(n2 + 1));
        
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    store[i][j] = 1 + store[i - 1][j - 1];
                } else {
                    store[i][j] = max(store[i - 1][j], store[i][j - 1]);
                }
                // cout << store[i][j] << " ";
            }
            // cout << endl;
        }
        
        vector<char> longestCommonSubsequence;
        int i = n1;
        int j = n2;
        while (i > 0 && j > 0) {
        // cout << 'f' << endl;
                // cout << i << " " << j << endl;
            if (str1[i - 1] == str2[j - 1]) {
                longestCommonSubsequence.push_back(str1[i - 1]);
                
                i--;
                j--;
                // cout << str1[i - 1] << endl;

            } else if (store[i - 1][j] >= store[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        // cout << 'f' << endl;
        
        // string s = string(longestCommonSubsequence.rbegin(), longestCommonSubsequence.rend());
        // cout << s << endl;
        // return "";
        return string(longestCommonSubsequence.rbegin(), longestCommonSubsequence.rend());
        
    }
    
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        string longestCommonSubsequence = lcs(str1, str2); 
        // return "";
        int i = 0;
        int j = 0;
        string result = "";
        for (int k = 0; k < longestCommonSubsequence.size(); k++) {
            while (str1[i] != longestCommonSubsequence[k]) {
                result += str1[i];
                i++;
            }
            
            while (str2[j] != longestCommonSubsequence[k]) {
                result += str2[j];
                j++;
            }
            
            
            result += longestCommonSubsequence[k];
            i++;
            j++;
            
            if (k == longestCommonSubsequence.size() - 1) {
                while (i < str1.size()) {
                    result += str1[i];
                    i++;
                }
                
                while (j < str2.size()) {
                    result += str2[j];
                    j++;
                }
            }
        }
        
        return result;
    }
};