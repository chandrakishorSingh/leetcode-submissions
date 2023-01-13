class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        string result = "";
        
        bool isBulky = ((int64_t)length * width * height >= 1e9) || (length >= 1e4) || (width >= 1e4) || (height >= 1e4);
        bool isHeavy = mass >= 100;
        
        if (isBulky && isHeavy) {
            result = "Both";
        } else if (!isBulky && !isHeavy) {
            result = "Neither";
        } else if (isBulky && !isHeavy) {
            result = "Bulky";
        } else {
            result = "Heavy";
        }
        
        return result;
    }
};

// TC: O(1)
// SC: O(1)