class Solution {
public:
    string robotWithString(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
        
        for (int i = 0; i < s.size(); i++)
            pq.push({ s[i], i });
        
        int index = 0;
        stack<char> st;
        string result = "";
        while (!pq.empty()) {
            auto top = pq.top();
            
            if (top.second < index) {
                pq.pop();
                continue;
            }
            
            if (st.empty() || st.top() > top.first) {
                pq.pop();
                
                result += string(1, top.first);
            
                while (index != top.second) {
                    st.push(s[index]);
                    index++;
                }
                index++;
                
            } else {
                char ch = st.top();
                st.pop();
                
                result += string(1, ch);
            }
        }
        
        while (!st.empty()) {
            char ch = st.top();
            st.pop();
            
            result += string(1, ch);
        }
        
        return result;
    }
};

// 