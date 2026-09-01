class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        // vector<vector<bool>>dp(n,vector<bool>(n,false));
        int cnt=0;
        vector<bool>nxt(n,false);
        for(int i=n-1;i>=0;i--){
            vector<bool>curr(n,false);
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i<=2 || nxt[j-1]==true)){
                    curr[j]=true;
                    cnt++;
                } 
            }
            nxt=curr;
        }
        return cnt;


        
    }
};
