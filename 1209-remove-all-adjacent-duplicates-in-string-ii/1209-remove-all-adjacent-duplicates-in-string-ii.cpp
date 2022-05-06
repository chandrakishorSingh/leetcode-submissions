class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        
        for (auto ch: s) {
            if (!st.empty() && st.top().first == ch) {
                st.push({ ch, st.top().second + 1 });
            } else {
                st.push({ch, 1});
            }
            
            if (!st.empty() && st.top().second == k) {
                for (int i = 0; i < k; i++)
                    st.pop();
            }
        }
        
        string result = "";
        while (!st.empty()) {
            result += st.top().first;   
            st.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};