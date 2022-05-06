class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        
        for (auto ch: s) {
            if (!st.empty() && st.top().first == ch) {
                st.top().second += 1;
            } else {
                st.push({ch, 1});
            }
            
            if (!st.empty() && st.top().second == k) {
                st.pop();
            }
        }
        
        string result = "";
        while (!st.empty()) {
            result += string(st.top().second, st.top().first);   
            st.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};

// TC: O(n)
// SC: O(n)