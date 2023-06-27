class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> start;
        priority_queue<int, vector<int>, greater<int>> end;
        
        int left = 0;
        int right = costs.size() - 1;
        for (int i = 0; i < candidates; i++) {
            if (left > right) {
                break;
            }
            
            start.push(costs[left]);
            left++;
            
            if (left > right) {
                break;
            }
            
            end.push(costs[right]);
            right--;
        }
        
        long long result = 0;
        while (k--) {
            bool flag = true;
            
            if (start.empty() || (!end.empty() && start.top() > end.top())) {
                flag = false;
            }
            
            if (flag) {
                result += start.top();
                start.pop();
            } else {
                result += end.top();
                end.pop();
            }
            
            if (left <= right) {
                if (flag) {
                    start.push(costs[left]);
                    left++;
                } else {
                    end.push(costs[right]);
                    right--;
                }
            }
        }
        
        return result;
    }
};