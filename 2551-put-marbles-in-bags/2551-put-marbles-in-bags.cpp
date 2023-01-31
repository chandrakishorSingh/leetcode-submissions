class Solution {
public:
    typedef long long ll;
    
    long long putMarbles(vector<int>& weights, int k) {
        priority_queue<int> maxPQ;
        priority_queue<int, vector<int>, greater<int>> minPQ;
        
        for (int i = 0; i < weights.size() - 1; i++) {
            int value = weights[i] + weights[i + 1];
            
            maxPQ.push(value);
            minPQ.push(value);
        }
        
        ll result = 0;
        while (k > 1) {
            result += maxPQ.top() - minPQ.top();
            
            maxPQ.pop();
            minPQ.pop();
            
            k--;
        }
        
        return result;
    }
};