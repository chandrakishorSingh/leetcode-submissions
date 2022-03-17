class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> result;
        
        int carry = 1;
        for (int i = n - 1; i >= 0; i--) {
            int sum = (digits[i] + carry) % 10;
            carry = (digits[i] + carry) / 10;
            
            result.push_back(sum);
        }
        
        if (carry != 0)
            result.push_back(1);
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};