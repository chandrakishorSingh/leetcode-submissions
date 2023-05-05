class Solution {
public:
    int maxVowels(string s, int k) {
        int result = 0;
        
        int vowelCount = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                vowelCount++;
            }
            
            if (i >= k && isVowel(s[i - k])) {
                vowelCount--;
            }
            
            result = max(result, vowelCount);
        }
        
        return result;
    }
    
    bool isVowel(char ch) {
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        return vowels.count(ch);
    }
};