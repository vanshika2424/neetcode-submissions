class Solution {
public:
    
    int solve(int i,int target,int offset,vector<int>&nums,vector<vector<int>>&dp){
        if(target<-offset || target>offset) return 0;
        if(i==0){
            int ways=0;
            if(target==nums[0]){
                ways++;
            }
            if(target==-nums[0]){
                ways++;
            }
            return ways;
        }
        if(dp[i][target+offset]!=-1){
            return dp[i][target+offset];
        }
        int add=solve(i-1,target-nums[i],offset,nums,dp);
        int sub=solve(i-1,target+nums[i],offset,nums,dp);
        return dp[i][target+offset]=add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(abs(target)>sum) return 0;
        vector<vector<int>>dp(n,vector<int>(2*sum+1,-1));
        return solve(n-1,target,sum,nums,dp);
    }
};
