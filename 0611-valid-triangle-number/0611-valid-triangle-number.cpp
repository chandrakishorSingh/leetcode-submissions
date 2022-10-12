class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        // for (auto num: nums)
        //     cout << num << " ";
        
        // cout << endl;
        
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                
                if (nums[i] == 0 || nums[j] == 0)
                    continue;
                
                auto left = lower_bound(nums.begin(), nums.end(), nums[j] - nums[i] + 1);
                auto right = upper_bound(nums.begin(), nums.end(), nums[j] + nums[i] - 1) - 1;
                
                int count = right - left;
                
                if (left <= nums.begin() + i && count > 0)
                    count--;
                
                result += count;
                
                // cout << left - nums.begin() << " " << right - nums.begin() << " " << count << endl;
            }
        }
        
        return result / 3;
    }
    
    bool isValidTriangleSides(int a, int b, int c) {
        if (a == 0 || b == 0 || c == 0)
            return false;
        
//         if (a + b <= c || b + c <= a || c + a <= b)
//             return false;
        
        if (abs(a - b) >= c || abs(b - c) >= a || abs(c - a) >= b)
            return false;
        
        return true;
    }
};

// TC: O(n^3)
// SC: O(1)