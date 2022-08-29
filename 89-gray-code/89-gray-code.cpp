class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 1)
            return {0, 1};
        
        auto result = grayCode(n - 1);
        
        int size = result.size();
        for (int i = size - 1; i >= 0; i--) {
            auto num = result[i];
            num = num + (1 << (n - 1));
            
            result.push_back(num);
        }
        
        return result;
    }
};

// TC: O(2^n)
// SC: O(n), except the output