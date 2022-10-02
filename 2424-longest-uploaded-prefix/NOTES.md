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
- Let each of the video be a node. Let there will be an edge between two nodes if they have been uploaded and are adjacent to each other.
- It's easy to see that the set of videos that have contiguous indices and have been uploaded form a connected component.
- So, we just need to find the size of connected component that have the node 1.
​
```
​
```