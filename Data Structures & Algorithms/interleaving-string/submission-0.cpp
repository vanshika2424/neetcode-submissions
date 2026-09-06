class Solution {
public:
    int solve(int k,int i,int j,string s1,string s2,string s3,vector<vector<vector<int>>>&dp){
        if(k==s3.size()){
            return true;
        }
        if(dp[k][i][j]!=-1){
            return dp[k][i][j];
        }
        if(i<s1.size() && s3[k]==s1[i]){
            if(solve(k+1,i+1,j,s1,s2,s3,dp)){
                return dp[k][i][j]=true;
            }
        }
        if(j<s2.size() && s3[k]==s2[j]){
            if(solve(k+1,i,j+1,s1,s2,s3,dp)){
                return dp[k][i][j]=true;
            }
        }
        return dp[k][i][j]=false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int l=s3.size();
        if(n+m!=l) return false;
        vector<vector<vector<int>>>dp(l,vector<vector<int>>(n+1,vector<int>(m+1,-1)));
        return solve(0,0,0,s1,s2,s3,dp);
        
    }
};
