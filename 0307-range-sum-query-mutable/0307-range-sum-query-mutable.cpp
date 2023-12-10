class NumArray {
public:
    class SegmentTree {
        private:
            vector<int> tree;
        
        void buildTree(int node, int left, int right, vector<int>& nums) {
            if (left == right) {
                tree[node] = nums[left];
                
                return;
            }
            
            int mid = (left + right) / 2;
            buildTree(2 * node, left, mid, nums);
            buildTree(2 * node + 1, mid + 1, right, nums);
            
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
        
        public:
        SegmentTree(vector<int>& nums) {
            int n = nums.size();
            tree.resize(4 * n);
            
            buildTree(1, 0, n - 1, nums);
        }
        
        void update(int node, int left, int right, int index, int val) {
            if (index < left || index > right) {
                return;
            }
            
            if (left == right) {
                tree[node] = val;
                return;
            }
            
            int mid = (left + right) / 2;
            update(2 * node, left, mid, index, val);
            update(2 * node + 1, mid + 1, right, index, val);
            
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
        
        int sum(int node, int treeLeft, int treeRight, int queryLeft, int queryRight) {
            if (queryLeft > queryRight) {
                return 0;
            }
            
            if (treeLeft == queryLeft && treeRight == queryRight) {
                return tree[node];
            }
            
            int treeMid = (treeLeft + treeRight) / 2;
            return 
                sum(2 * node, treeLeft, treeMid, queryLeft, min(treeMid, queryRight)) +
                sum(2 * node + 1, treeMid + 1, treeRight, max(treeMid + 1, queryLeft), queryRight);
        }
    };
    
    int n;
    SegmentTree* tree;
    
    NumArray(vector<int>& nums) {
        this->n = nums.size();
        tree = new SegmentTree(nums);
    }
    
    void update(int index, int val) {
        tree->update(1, 0, this->n - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return tree->sum(1, 0, this->n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */