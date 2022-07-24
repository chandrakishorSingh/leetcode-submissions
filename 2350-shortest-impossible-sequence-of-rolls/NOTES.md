startIndex = maxStartIndex + 1;
}
return result;
}
int binarySearch(int target, vector<int>& arr) {
int low = 0;
int high = arr.size() - 1;
int result = -1;
while (low <= high) {
int mid = low + (high - low) / 2;
if (arr[mid] < target) {
low = mid + 1;
} else {
result = arr[mid];
high = mid - 1;
}
}
return result;
}
};
​
// TC: O(n * log(n))
// SC: O(k + n)
```