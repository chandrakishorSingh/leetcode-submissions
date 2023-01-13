result = "Bulky";
} else {
result = "Heavy";
}
return result;
}
bool isBulky(int length, int width, int height, int mass) {
int64_t volume = (int64_t)length * width * height;
return (volume >= 1e9) || (length >= 1e4) || (width >= 1e4) || (height >= 1e4);
}
bool isHeavy(int mass) {
return mass >= 100;
}
};
​
// TC: O(1)
// SC: O(1)
```
​
Solution 2:
​
- A more concise implementation using 2D array.