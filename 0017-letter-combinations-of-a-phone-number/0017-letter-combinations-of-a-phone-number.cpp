class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        
        unordered_map<char, vector<char>> digitToCharsMap;
        digitToCharsMap['2'] = {'a', 'b', 'c'};
        digitToCharsMap['3'] = {'d', 'e', 'f'};
        digitToCharsMap['4'] = {'g', 'h', 'i'};
        digitToCharsMap['5'] = {'j', 'k', 'l'};
        digitToCharsMap['6'] = {'m', 'n', 'o'};
        digitToCharsMap['7'] = {'p', 'q', 'r', 's'};
        digitToCharsMap['8'] = {'t', 'u', 'v'};
        digitToCharsMap['9'] = {'w', 'x', 'y', 'z'};
        
        
        string current = "";
        _letterCombinations(0, digits, current, digitToCharsMap, result);
        
        return result;
    }
    
    void _letterCombinations(int index, string& digits, string& current, unordered_map<char, vector<char>>& digitToCharsMap, vector<string>& result) {
        if (index == digits.size() && digits.size() > 0) {
            result.push_back(current);
            return;
        }
        
        for (auto ch: digitToCharsMap[digits[index]]) {
            current.push_back(ch);
            _letterCombinations(index + 1, digits, current, digitToCharsMap, result);
            current.pop_back();
        }
    }
};

// 