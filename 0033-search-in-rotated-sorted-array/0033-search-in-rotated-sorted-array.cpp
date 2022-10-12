class Solution {
public:
    int search(vector<int>& arr, int search_element) {
int low = 0, high = arr.size();

    while (low < high) {
        int mid = low + (high - low) / 2;

        int curr;

        // Check if search_element
        // falls in first half or
        // second half
        if ((arr[mid] < arr[0])
            == (search_element < arr[0])) {
            curr = arr[mid];
        }

        // If search_element falls in
        // second half take min number
        else if (search_element < arr[0]) {
            curr = INT_MIN;
        }

        // If search_element falls in
        // first half take max number
        else {
            curr = INT_MAX;
        }

        // Perform binary search
        // to find the key
        if (curr < search_element) {
            low = mid + 1;
        }
        else if (curr > search_element) {
            high = mid;
        }
        else {
            return mid;
        }
    }

    return -1;
    }
};