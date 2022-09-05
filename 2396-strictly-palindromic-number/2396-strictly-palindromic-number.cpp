class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        bool result = true;
        
        for (int base = 2; base <= n - 2; base++) {
            auto numString = toBase(base, n);
            
            if (!isPalindrome(numString)) {
                result = false;
                break;
            }
        }
        
        return result;
    }
    
    string toBase(int base, int number) {
        stack<int> st;
        
        while (number != 0) {
            st.push(number % base);
            number /= base;
        }
        
        string result = "";
        while (!st.empty()) {
            char digit = st.top() + '0';
            result.append(1, digit);
            
            st.pop();
        }
        
        return result;
    }
    
    bool isPalindrome(string& str) {
        int left = 0;
        int right = str.size() - 1;
        
        while (left < right) {
            if (str[left] != str[right])
                return false;
            
            left++;
            right--;
        }
        
        return true;
    }
};