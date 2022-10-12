​
return left2 == -1 ? -1 : binarySearch(vec, left2, right2, k);
}
​
int binarySearch(vector<int>& vec, int left, int right, int k) {
int result = -1;
​
while (left <= right) {
int mid = left + (right - left) / 2;
​
if (vec[mid] == k) {
result = mid;
break;
} else if (vec[mid] > k) {
right = mid - 1;
} else {
left = mid + 1;
}
}
​
return result;
}
};
​
// TC: O(log(n))
// SC: O(1)
​
```