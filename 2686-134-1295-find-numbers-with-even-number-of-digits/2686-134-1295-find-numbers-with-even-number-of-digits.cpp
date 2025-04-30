class Solution {
private:
    int countDigits(int num) {
        int result = 0;
        
        while (num != 0) {
            num /= 10;
            result++;
        }
        
        return result;
    }
    
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        
        for (auto num: nums) {
            if (countDigits(num) % 2 == 0) {
                result++;
            }
        }
        
        return result;
    }
};