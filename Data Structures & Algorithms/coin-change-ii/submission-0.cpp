class Solution {
public:
    int solve(int i,int amt,vector<int>& coins,vector<vector<int>>&dp){
        if(i==0){
            if(amt % coins[i]==0){
                return 1;

            }
            return 0;
            
        }
        if(dp[i][amt]!=-1){
            return dp[i][amt];
        }
        int take=0;
        if(coins[i]<=amt) take=solve(i,amt-coins[i],coins,dp);
        int nottake=solve(i-1,amt,coins,dp);
        return dp[i][amt]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);
        
    }
};
