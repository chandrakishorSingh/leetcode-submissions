class Solution {
public:
    int mirrorReflection(int p, int q) {
        int directionX = 1;
        int directionY = 1;
        int y = q;
        
        int result = -1;
        while (true) {
            if (directionX == 1 && y == 0) {
                result = 0;
                break;
            }

            if (directionX == 1 && y == p) {
                result = 1;
                break;
            }
            
            if (directionX == -1 && y == p) {
                result = 2;
                break;
            }
            
            if (directionY == 1) {
                y += q;
                
                if (y > p) {
                    y = 2 * p - y;
                    directionY = -directionY;
                }
            } else {
                y -= q;
                
                if (y < 0) {
                    y = -y;
                    directionY = -directionY;
                }
            }
            
            directionX = -directionX;
        }
        
        return result;
    }
};