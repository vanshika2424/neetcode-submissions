class Solution {
public:
    int solve(int i,vector<int>& nums,vector<int>& dp){
        if(i<0){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int rob=solve(i-2,nums,dp)+nums[i];
        int notrob=solve(i-1,nums,dp);
        return dp[i]=max(rob,notrob);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>dp1(n-1,-1);
        vector<int>dp2(n-1,-1);
        vector<int>first;
        vector<int>second;
        for(int i=0;i<n;i++){
            if(i==0){
                first.push_back(nums[i]);
            }
            else if(i==n-1){
                second.push_back(nums[i]);
            }
            else{
                first.push_back(nums[i]);
                second.push_back(nums[i]);
            }
        }
        return max(solve(n-2,first,dp1),solve(n-2,second,dp2));
        
    }
};
