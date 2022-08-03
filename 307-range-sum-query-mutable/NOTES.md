int parent = getParentIndex(i);
if (parent <= n)
tree[parent] += tree[i];
}
}
void update(int index, int val) {
int delta = val - sumRange(index, index);
int n = tree.size() - 1;
index++;
while (index <= n) {
tree[index] += delta;
index = getParentIndex(index);
}
}
int sumRange(int left, int right) {
return prefixSum(right + 1) - prefixSum(left);
}
};
​
/**
* Your NumArray object will be instantiated and called as such:
* NumArray* obj = new NumArray(nums);
* obj->update(index,val);
* int param_2 = obj->sumRange(left,right);
*/
```