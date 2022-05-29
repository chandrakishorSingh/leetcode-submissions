class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();

        vector<vector<int>> alphabets(n, vector<int>(26));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < words[i].size(); j++)
                alphabets[i][words[i][j] - 'a'] = 1;

        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                bool hasCommonChars = false;
                for (int k = 0; k < 26; k++) {
                    if (alphabets[i][k] && alphabets[j][k]) {
                        hasCommonChars = true;
                        break;
                    }
                }

                if (!hasCommonChars)
                    result = max(result, (int)words[i].size() * (int)words[j].size());
            }
        }

        return result;
    }
};

// TC: O(n^2 + sum(len(words[i])))
// SC: O(n)