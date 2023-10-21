class Solution {
private:
    bool _isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
    
    int _minCut(string& s, int left, int right, vector<vector<int>>& store) {
        if (store[left][right] != -1) {
            return store[left][right];
        }
        
        if (_isPalindrome(s, left, right)) {
            store[left][right] = 0;
            return store[left][right];
        }
        
        int result = right - left;
        for (int i = left; i < right; i++) {
            if (_isPalindrome(s, left, i)) {
                result = min(result, 1 + _minCut(s, i + 1, right, store));
            }
        }
        
        store[left][right] = result;
        
        return store[left][right];
    }
    
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> store(n, vector<int>(n, -1));
        
        return _minCut(s, 0, n - 1, store);
    }
};

// TC: ?
// SC: O(len(s))