class Solution {
public:
    int solve(int i,int n,string s,vector<int>&dp){
        if(i==n){
            return 1;
        }
        if(dp[i]!=-1) return dp[i];
        if(s[i]=='0') return 0;
        int way1=solve(i+1,n,s,dp);
        int way2=0;
        string str=s.substr(i,2);
        if(i<n-1 && str>="1" && str<="26") way2=solve(i+2,n,s,dp);
        return dp[i]=way1+way2;
    }
    int numDecodings(string s) {

        int n=s.length();
        vector<int>dp(n,-1);
        return solve(0,n,s,dp);
        
    }
};
