class Solution {
public:
    // int solve(int i,int j,int n,vector<int>&nums,vector<vector<int>>& dp){
    //     if(i==n){
    //         return 0;
    //     }
    //     if(dp[i][j+1]!=-1){
    //         return dp[i][j+1];
    //     }
    //     int take=0;
    //     if(j==-1|| nums[i]>nums[j]){
    //         take=1+solve(i+1,i,n,nums,dp);
    //     }
    //     int nottake=solve(i+1,j,n,nums,dp);
    //     return dp[i][j+1]=max(take,nottake);
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<int>ans;
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return solve(0,-1,n,nums,dp);

        vector<vector<int>>dp(n+1,vector<int>(n+1));
        for(int i=0;i<=n;i++){
            dp[n][i]=0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int take=0;
                if(j==-1|| nums[i]>nums[j]){
                    take=1+dp[i+1][i+1];
                }
                int nottake=dp[i+1][j+1];
                dp[i][j+1]=max(take,nottake);    
            }
        }
        return dp[0][0];



        
    }
};
