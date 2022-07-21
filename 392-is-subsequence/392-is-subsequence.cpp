class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index = 0;
        for (int i = 0; i < t.size() && index < s.size(); i++) {
            if (t[i] == s[index])
                index++;
        }
        
        return index == s.size();
    }
};

// TC: O(2^n * n)
// SC: O(n)
// n = length of t