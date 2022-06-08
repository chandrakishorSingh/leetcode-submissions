class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = 0;
        
        for (int i = 0; i < 31; i++)
            if (((1 << i) & x) != ((1 << i) & y))
                result++;
        
        return result;
    }
};

// TC: O(1)
// SC: O(1)