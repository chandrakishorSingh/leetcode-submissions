Solution 1:
​
- Straightforward approach.
​
```
class Solution {
public:
string categorizeBox(int length, int width, int height, int mass) {
string result = "";
bool isBulkyObject = isBulky(length, width, height, mass);
bool isHeavyObject = isHeavy(mass);
if (isBulkyObject && isHeavyObject) {
result = "Both";
} else if (!isBulkyObject && !isHeavyObject) {
result = "Neither";
} else if (isBulkyObject && !isHeavyObject) {
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