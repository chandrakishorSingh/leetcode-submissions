class Solution {
public:
    int countCollisions(string directions) {
        bool isLeftBlocked = false;
        int rightCount = 0;
        int collisionCount = 0;
        
        for (auto dir: directions) {
            if (dir == 'S') {
                isLeftBlocked = true;
                collisionCount += rightCount;
                rightCount = 0;
            } else if (dir == 'L') {
                if (!isLeftBlocked && rightCount == 0)
                    continue;
                
                collisionCount += rightCount + 1;
                rightCount = 0;
                isLeftBlocked = true;
            } else {
                rightCount++;
            }
        }
        
        
        return collisionCount;
    }
};

// TC: O(n)
// SC: O(n)