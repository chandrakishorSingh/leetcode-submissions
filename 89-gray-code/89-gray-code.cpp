class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        
        for (int i = 0; i < (1 << n); i++)
            result.push_back(toGrayCode(i));
        
        return result;
    }
    
    int toGrayCode(int n) {
        int result = n;
        
        for (int i = 14; i >= 0; i--) {
            auto bit = ((n & (1 << i)) > 0 ? 1: 0) ^ ((n & (1 << (i + 1))) > 0 ? 1: 0);
            
            if (bit) {
                result = result | (1 << i);
            } else {
                result = result & ~(1 << i);
            }
        }
        
        return result;
    }
};