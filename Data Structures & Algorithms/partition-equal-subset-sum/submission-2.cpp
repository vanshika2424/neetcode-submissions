class Solution {
public:
    // bool solve(int i,int target,vector<int>&nums,vector<vector<int>>&dp){
    //     if(target==0) return true;
    //     if(i==0){
    //         return (nums[0]==target);
    //     }
    //     if(dp[i][target]!=-1){
    //         return dp[i][target];
    //     }
    //     int take=false;
    //     if(nums[i]<=target){
    //         take=solve(i-1,target-nums[i],nums,dp);
    //     }
    //     int nottake=solve(i-1,target,nums,dp);
    //     return dp[i][target]=(take||nottake);
    // }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        
        if(sum%2!=0){
            return false;
        }
        int target=sum/2;

        vector<vector<bool>>dp(n,vector<bool>(target+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                int take=false;
                if(nums[i]<=j){
                    take=dp[i-1][j-nums[i]];
                }
                int nottake=dp[i-1][j];
                dp[i][j]=(take||nottake);

            }
        }
        return dp[n-1][target];


        
    }
};
