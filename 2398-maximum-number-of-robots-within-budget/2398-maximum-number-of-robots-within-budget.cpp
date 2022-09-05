class MaxStack {
public:
    int max() {
        return st.top().second;
    }
    
    void push(int num) {
        if (st.empty())
            st.push({ num, num });
        else
            st.push({ num, std::max(this->max(), num) });
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int size() {
        return st.size();
    }
    
    bool empty() {
        return st.empty();
    }
    
private:
    stack<pair<int, int>> st;
};

class MaxQueue {
public:
    int max() {
        if (st1.empty())
            return st2.max();
        
        if (st2.empty())
            return st1.max();
        
        return std::max(st1.max(), st2.max());
    }
    
    void push(int num) {
        st1.push(num);
    }
    
    void pop() {
        if (st2.empty())
            move(st1, st2);
        
        st2.pop();
    }
    
    int front() {
        if (st2.empty())
            move(st1, st2);
        
        return st2.top();
    }
    
    int size() {
        return st1.size() + st2.size();
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
    
private:
    MaxStack st1;
    MaxStack st2;
    
    void move(MaxStack& src, MaxStack& dest) {
        while (!src.empty()) {
            dest.push(src.top());
            src.pop();
        }
    }
};

class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int result = 0;
        
        int start = 0;
        long long currentRunningCosts = 0;
        MaxQueue que;
        for (int end = 0; end < chargeTimes.size(); end++) {
            currentRunningCosts += runningCosts[end];
            que.push(chargeTimes[end]);
            
            auto isUnderBudget = (que.max() + (end - start + 1) * currentRunningCosts) <= budget;
            while (!isUnderBudget && !que.empty()) {
                que.pop();
                currentRunningCosts -= runningCosts[start++];
                
                if (!que.empty())
                    isUnderBudget = (que.max() + (end - start + 1) * currentRunningCosts) <= budget;
                else
                    isUnderBudget = true;
            }
            
            result = max(result, end - start + 1);
        }
        
        return result;
    }
};

// TC: O(n)
// SC: O(n)