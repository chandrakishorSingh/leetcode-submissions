class Solution {
public:
    bool hasAllCodes(string s, int k) {
        vector<int> nums((int)pow(2, k));
        
        int n = s.size();
        int start = 0;
        int end = 0;
        int num = 0;
        for (; end < n; end++) {
            num = num << 1;
            num += s[end] == '1' ? 1: 0;
            
            if (end >= k - 1) {
                num = (num & (~(1 << k)));
                start++;
            }
            
            if (end >= k - 1)
                nums[num] = 1;
        }
        
        for (auto num: nums)
            if (num == 0)
                return false;
        
        return true;
    }
};