class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int middleIndex = (n1 + n2) / 2 + 1;
        
        int i = 0;
        int j = 0;
        int previousElement = 0;
        int middleElement = 0;
        while (middleIndex--) {
            previousElement = middleElement;
            
            if (i == n1) {
                middleElement = nums2[j++];
            } else if (j == n2) {
                middleElement = nums1[i++];
            } else if (nums1[i] <= nums2[j]) {
                middleElement = nums1[i++];
            } else {
                middleElement = nums2[j++];
            }
            
        }

        return (n1 + n2) % 2 == 0 ? ((middleElement + previousElement) / 2.0): middleElement;
    }
};
