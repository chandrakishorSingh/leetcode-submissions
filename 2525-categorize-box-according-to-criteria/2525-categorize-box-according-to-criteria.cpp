class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        string result = "";
        
        bool isBulky = ((int64_t)length * width * height >= 1e9) || (length >= 1e4) || (width >= 1e4) || (height >= 1e4);
        bool isHeavy = mass >= 100;
        
        vector<vector<string>> categories = {{"Neither", "Heavy"}, {"Bulky", "Both"}};
        
        return categories[isBulky][isHeavy];
    }
};

// TC: O(1)
// SC: O(1)