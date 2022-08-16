class Solution {
vector<int> slideMax(vector<vector<int>>&vec, int k,int col){
        priority_queue<pair<int,int>>pq;
        vector<int>res;
        pq.push({vec[0][col],0});
        for(int i = 1;i<vec.size();i++){
            while(pq.top().second+k<=i)
                pq.pop();
            pq.push({vec[i][col],i});
            if(i>=k-1)
                res.push_back(pq.top().first);
        }
        return res;
    }
    
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>res(n);
        for(int j = 0;j<n;j++)
            res[j] = slideMax(grid,3,j);
        
        vector<vector<int>>ans(n-2);
        for(int j = 0;j<n-2;j++)
            ans[j] = slideMax(res,3,j);
        return ans;
    }
};

// TC: O(m * n)
// SC: O(1), except the size for output