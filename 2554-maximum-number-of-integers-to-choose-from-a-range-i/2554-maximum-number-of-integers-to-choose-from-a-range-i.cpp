class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st;
        for (auto num: banned) {
            st.insert(num);
        }
        
        int result = 0;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (st.count(i)) {
                continue;
            }
            
            if (sum + i > maxSum) {
                break;
            }
            
            sum += i;
            result++;
        }
        
        return result;
    }
};

// TC: Θ(n)
// SC: O(len(banned))