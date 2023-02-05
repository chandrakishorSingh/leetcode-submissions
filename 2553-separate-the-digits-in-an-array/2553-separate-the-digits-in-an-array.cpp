class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        
        for (auto num: nums) {
            stack<int> st;
            while (num != 0) {
                int digit = num % 10;
                num /= 10;
                st.push(digit);
            }
            
            while (!st.empty()) {
                result.push_back(st.top());
                st.pop();
            }
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(1)