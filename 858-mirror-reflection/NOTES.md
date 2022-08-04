if (directionX == -1 && y == p) {
result = 2;
break;
}
if (directionY == 1) {
y += q;
if (y > p) {
y = 2 * p - y;
directionY = -directionY;
}
} else {
y -= q;
if (y < 0) {
y = -y;
directionY = -directionY;
}
}
directionX = -directionX;
}
return result;
}
};
```
​
​