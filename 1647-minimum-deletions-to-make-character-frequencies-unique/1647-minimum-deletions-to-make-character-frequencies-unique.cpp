class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26);
        
        for (auto ch: s)
            freq[ch - 'a']++;
        
        set<int> st;
        int result = 0;
        for (auto num: freq) {
            if (num == 0)
                continue;
            
            if (st.count(num)) {
                while (num != 0 && st.count(num)) {
                    num--;
                    result++;
                }
                
                if (num != 0)
                    st.insert(num);
            } else {
                st.insert(num);
            }
        }
        
        return result;
    }
};