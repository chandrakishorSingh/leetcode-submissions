result++;
} else {
break;
}
}
return result;
}
};
​
/**
* Your LUPrefix object will be instantiated and called as such:
* LUPrefix* obj = new LUPrefix(n);
* obj->upload(video);
* int param_2 = obj->longest();
*/
​
// TC: O(n * noOfQueries)
// SC: O(n)
```
​
Solution 2:
​
- Use BIT.
- When setting ith index, see if sum(arr[:i]) == `(i + 1) * (i + 2) / 2`. The maximum such i is the answer.
​
​