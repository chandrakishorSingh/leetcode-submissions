class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        set<char> st(vowels.begin(), vowels.end());
        
        int n = words.size();
        vector<int> stringKind(n);
        
        for (int i = 0; i < words.size(); i++) {
            if (st.count(words[i].front()) && st.count(words[i].back())) {
                stringKind[i] = 1;
            }
        }
        
        vector<int> prefixSum(n + 1);
        for (int i = 1; i <= n; i++) {
            prefixSum[i] += prefixSum[i - 1] + stringKind[i - 1];
        }
        
        int k = queries.size();
        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            
            result[i] = prefixSum[r + 1] - prefixSum[l];
        }
        
        return result;
    }
};

// TC: O(n + k)
// SC: O(n)
// n = len(words)
// k = len(queries)