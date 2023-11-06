class Solution {
private:
    void backtrack(int n, string& s, int isParenthesesBalanced, vector<string>& result) {
        if (n == 0) {
            if (isParenthesesBalanced == 0) {
                result.push_back(s);
            }
            
            return;
        }
        
        if (isParenthesesBalanced < 0) {
            return;
        }
        
        s.push_back('(');
        backtrack(n - 1, s, isParenthesesBalanced + 1, result);
        s.pop_back();
        
        s.push_back(')');
        backtrack(n - 1, s, isParenthesesBalanced - 1, result);
        s.pop_back();
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        
        string s = "";
        int isParenthesesBalanced = 0;
        
        backtrack(2 * n, s, isParenthesesBalanced, result);
        
        return result;
    }
};

// TC: O((2n)^2)
// SC: O(n), except the output