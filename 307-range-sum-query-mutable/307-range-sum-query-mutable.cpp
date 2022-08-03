class NumArray {
private:
    vector<int> tree;
    
    int getParentIndex(int i) {
        return i + (i & -i);
    }
    
    int getChildIndex(int i) {
        return i - (i & -i);
    }
    
    int prefixSum(int i) {
        int sum = 0;

        while (i >= 1) {
            sum += tree[i];
            i = getChildIndex(i);
        }
        
        return sum;
    }
    
    void printArray() {
        for (int i = 1; i < tree.size(); i++)
            cout << tree[i] << " ";
        cout << endl;
    }

public:    
    NumArray(vector<int>& nums) {
        int n = nums.size();
        tree.resize(n + 1);
        
        for (int i = 1; i <= n; i++) {
            tree[i] += nums[i - 1];
            
            int parent = getParentIndex(i);
            // cout << "parent of " << i << " is " << parent << endl;
            // cout << "parent of " << i << " is " << parent << endl;
            if (parent <= n) {
                tree[parent] += tree[i];
            }
        }
        
        // printArray();
    }
    
    void update(int index, int val) {
        int delta = val - sumRange(index, index);
        
        // cout << sumRange(index, index) << endl;
        // cout << delta << endl;
        
        int n = tree.size() - 1;
        index++;
        while (index <= n) {
            tree[index] += delta;
            // cout << "after updating index = " << index << " value is " << tree[index] << endl; 
            index = getParentIndex(index);
        }
        
        // printArray();
        
    }
    
    int sumRange(int left, int right) {
        return prefixSum(right + 1) - prefixSum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */