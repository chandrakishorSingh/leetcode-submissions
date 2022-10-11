class Solution {
public:
    int search(vector<int>& vec, int k) {
        int n = vec.size();
        int left1 = 0;
        int right1 = n - 1;
        int left2 = -1;
        int right2 = -1;

        for (int i = 1; i < n; i++) {
            if (vec[i] < vec[i - 1]) {
                right1 = i - 1;

                left2 = i;
                right2 = n - 1;

                break;
            }
        }
        
        int result = binarySearch(vec, left1, right1, k);

        if (result != -1)
            return result;

        return left2 == -1 ? -1 : binarySearch(vec, left2, right2, k);
    }
    

    int binarySearch(vector<int>& vec, int left, int right, int k) {
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (vec[mid] == k) {
                result = mid;
                break;
            } else if (vec[mid] > k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }    
};