class Solution {
public:
    int solve(int i,int n,int b,vector<int>& prices,vector<vector<int>>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i][b]!=-1){
            return dp[i][b];
        }
        if(b==0){
            int buy=-prices[i]+solve(i+1,n,1,prices,dp);
            int notbuy=solve(i+1,n,b,prices,dp);
            return dp[i][b]=max(buy,notbuy);
        }
        else{
            int sell=prices[i]+solve(i+2,n,0,prices,dp);
            int notsell=solve(i+1,n,b,prices,dp);
            return dp[i][b]=max(sell,notsell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,n,0,prices,dp);
        
    }
};
