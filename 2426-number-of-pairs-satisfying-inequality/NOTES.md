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
​
// TC: O(n * log(n))
// SC: O(n)
```
​