class Solution {
public:
    int solve(int i,int amt,vector<int>& coins,vector<vector<int>>& dp){
        if(i==0){
            if(amt % coins[i]==0){
                return amt/coins[i];
            }
            return INT_MAX;
        }
        int take=INT_MAX;
        if(coins[i]<=amt){
            take=solve(i,amt-coins[i],coins,dp);
            if(take!=INT_MAX){
                take=1+take;
            }

        } 
        int nottake=solve(i-1,amt,coins,dp);
        return dp[i][amt]=min(take,nottake);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,amount,coins,dp);
        if(ans==INT_MAX) return -1;
        return ans;
        
    }
};
