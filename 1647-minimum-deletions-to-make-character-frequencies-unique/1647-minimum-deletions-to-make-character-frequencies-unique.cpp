class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26);
        
        for (auto ch: s)
            freq[ch - 'a']++;

        priority_queue<int> pq(freq.begin(), freq.end());
        int result = 0;
        while (pq.size() != 1) {
            auto top = pq.top();
            pq.pop();
            
            if (top == 0 || top != pq.top())
                continue;
            
            pq.push(top - 1);
            result++;
        }
        
        return result;
    }
};

// TC: O(n + k^2 * log(k))
// SC: O(k)