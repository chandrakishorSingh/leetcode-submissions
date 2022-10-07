class BIT{
    vector<int> bit;
    public:
    int N;
    BIT(int n){
        bit = vector<int> (n + 1);
        N = n;
    }
    
    void upd(int i,int val){
        i+=1;
        for(;i <= N;i+=(i & -i)){
            bit[i] += val;
        }
    }
    
    int summ(int i){
       int sum = 0;
        i+=1;
         for(;i > 0;i-=(i & -i)){
            sum += bit[i];
        }   
        return sum;
    }
    
};



class Solution {
public:
    long long numberOfPairs(vector<int>& a, vector<int>& b, int diff) {
        
        int n = a.size();
        
        long long ans = 0;
        
        int c = 1e5;
        
        BIT* bb = new BIT(10*c + 1);

        bb->upd(a[0] - b[0] + c, 1);

        for(int j=1;j<n;j++){
            int x = bb->summ(a[j] - b[j] + diff + c);
            ans += x;            
            bb->upd(a[j] - b[j] + c,1);
        }
        
        return ans;
        
        
        
        
        
    }
};