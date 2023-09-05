class Solution {
private:
    bool isSymmetric(string& num) {
        int sum1 = 0;
        for (int i = 0; i < num.size() / 2; i++) {
            sum1 += num[i] - '0';
        }
        
        int sum2 = 0;
        for (int i = num.size() / 2; i < num.size(); i++) {
            sum2 += num[i] - '0';
        }
        
        return sum1 == sum2;
    }

public:
    int countSymmetricIntegers(int low, int high) {
        int result = 0;
        
        for (int i = low; i <= high; i++) {
            auto num = to_string(i);
            
            if (num.size() % 2 == 0 && isSymmetric(num)) {
                result++;
            }
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(1)