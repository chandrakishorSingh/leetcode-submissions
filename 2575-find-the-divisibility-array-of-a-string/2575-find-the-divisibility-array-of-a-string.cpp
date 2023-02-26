class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        int64_t remainder = 0;
        
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int digit = word[i] - '0';
            remainder = (((remainder * (10 % m)) % m) + (digit % m)) % m;
            result[i] = remainder == 0 ? 1 : 0;
        }
        
        return result;
    }
};