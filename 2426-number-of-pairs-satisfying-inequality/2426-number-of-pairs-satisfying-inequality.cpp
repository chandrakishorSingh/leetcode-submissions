class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        
        vector<int> differences(n), aux(n);
        for (int i = 0; i < n; i++) {
            differences[i] = nums1[i] - nums2[i];
        }
        
        long long result = 0;
        mergeSort(differences, aux, 0, n - 1, diff, result);
        
        return result;
    }
    
    void mergeSort(vector<int>& differences, vector<int>& aux, int left, int right, int& diff, long long& result) {
        if (left == right)
            return;
        
        int mid = left + ((right - left) / 2);
        mergeSort(differences, aux, left, mid, diff, result);
        mergeSort(differences, aux, mid + 1, right, diff, result);
        
        for (int i = left; i <= right; i++) {
            aux[i] = differences[i];
        }
        
        int it1 = left;
        int it2 = mid + 1;
        for (int i = left; i <= right; i++) {
            if (it1 > mid || it2 > right) {
                break;
            }
            
            if (aux[it1] - diff <= aux[it2]) {
                result += (right - it2 + 1);
                it1++;
            } else {
                it2++;
            }
        }
        
        it1 = left;
        it2 = mid + 1;
        for (int i = left; i <= right; i++) {
            if (it1 > mid) {
                differences[i] = aux[it2++];
            } else if (it2 > right) {
                differences[i] = aux[it1++];
            } else if (aux[it1] <= aux[it2]) {
                differences[i] = aux[it1++];
            } else {
                differences[i] = aux[it2++];
            }
        }
    }
};