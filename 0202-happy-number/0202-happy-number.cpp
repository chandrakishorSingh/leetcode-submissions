class Solution {
public:
    bool isHappy(int n) {
        vector<int> squares = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
        
        set<int> states;
        int currentState = n;
        while (true) {
            if (states.count(currentState))
                return false;
            
            if (currentState == 1)
                break;
            
            states.insert(currentState);
            
            int nextState = 0;
            while (currentState != 0) {
                int digit = currentState % 10;
                nextState += squares[digit];
                currentState /= 10;
            }
            
            currentState = nextState;
        }
        
        return true;
    }
};