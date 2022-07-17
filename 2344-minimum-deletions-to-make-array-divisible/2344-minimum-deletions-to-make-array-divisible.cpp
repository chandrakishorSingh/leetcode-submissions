class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int64_t gcd = numsDivide[0];
        
        for (auto num: numsDivide)
            gcd = __gcd(gcd, (int64_t)num);
        
        sort(nums.begin(), nums.end());
        
        int removeCount = 0;
        int flag = false;
        for (int i = 0; i < nums.size(); i++) {
            if (gcd % nums[i] == 0) {
                flag = true;
                break;
            }
            removeCount++;
        }
        
        if (flag)
            return removeCount;
        
        return -1;
    }
};