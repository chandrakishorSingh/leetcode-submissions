class Solution {
public:
    bool isAnagram(string s, string t) {
        map<int, int> mp1;
        for (auto ch: s)
            mp1[ch]++;
        
        map<int, int> mp2;
        for (auto ch: t)
            mp2[ch]++;
        
        if (mp1.size() != mp2.size())
            return false;
        
        for (auto it = mp1.begin(); it != mp1.end(); it++)
            if (it->second != mp2[it->first])
                return false;
        
        return true;
    }
};