class Solution {
public:
    bool solve(int i,string s,set<string>st,vector<string>& wordDict,vector<int>&dp){
        if(i==s.size()){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        for(int j=i;j<s.size();j++){
            if(st.count(s.substr(i,j-i+1))){
                if(solve(j+1,s,st,wordDict,dp)){
                    return dp[i]=true;
                }
            }
        }
        return dp[i]=false;
        
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=wordDict.size();
        set<string>st;
        vector<int>dp(s.size(),-1);
        for(int i=0;i<n;i++){
            st.insert(wordDict[i]);
        }
        return solve(0,s,st,wordDict,dp);
        
        
    }
};
