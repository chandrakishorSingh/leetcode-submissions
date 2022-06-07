class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> charIndices(26, -1);
        
        for (int i = 0; i < s.size(); i++) {
            int index = s[i] - 'a';
            
            if (charIndices[index] == -1)
                charIndices[index] = i;
            else
                charIndices[index] = -2;
        }
        
        int minIndex = INT_MAX;
        for (int i = 0; i < 26; i++)
            if (charIndices[i] >= 0)
                minIndex = min(minIndex, charIndices[i]);
        
        return minIndex == INT_MAX ? -1: minIndex;
    }
};