class Solution {
public:
    int solve(int i,int j,string s1,string s2,string s3,vector<vector<int>>&dp){
        if(i+j==s3.size()){
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i<s1.size() && s3[i+j]==s1[i]){
            if(solve(i+1,j,s1,s2,s3,dp)){
                return dp[i][j]=true;
            }
        }
        if(j<s2.size() && s3[i+j]==s2[j]){
            if(solve(i,j+1,s1,s2,s3,dp)){
                return dp[i][j]=true;
            }
        }
        return dp[i][j]=false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int l=s3.size();
        if(n+m!=l) return false;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,s1,s2,s3,dp);
        
    }
};
