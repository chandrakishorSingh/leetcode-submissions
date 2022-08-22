class Solution {

    public int coinChange(int[] coins, int amount) {
        
         Integer[][] dp=new Integer[coins.length][amount+1];
        //for(int[] x:dp)Arrays.fill(x,-1);
        int res=f(coins.length-1,coins,amount,dp);
        return res>=(int)1e9?-1:res;
    }
    public int f(int i,int[] coins, int amt,Integer[][] dp) {
        if(amt==0)return 0;
        if(i<0) return (int)1e9;
        if(dp[i][amt]!=null)return dp[i][amt];
        int pick=(int)1e9;
        if(amt>=coins[i]) pick=1+f(i,coins,amt-coins[i],dp);
        
        int notpick=f(i-1,coins,amt,dp);
        
        return dp[i][amt]=Math.min(pick,notpick);
        
    }
}