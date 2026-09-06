class Solution {
public: 
    int dr[4]={-1,+1,0,0};
    int dc[4]={0,0,-1,+1};
    int dfs(int i,int j,int n,int m,vector<vector<int>>& matrix,vector<vector<int>>& dp){

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int maxi=0;
        for(int r=0;r<4;r++){
            int row=i+dr[r];
            int col=j+dc[r];
            if(row>=0 && row<n && col>=0 && col<m && matrix[row][col]>matrix[i][j]){
                maxi=max(maxi,1+dfs(row,col,n,m,matrix,dp));
            }
        }
        return dp[i][j]=maxi;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==-1) maxi=max(maxi,1+dfs(i,j,n,m,matrix,dp));
            }
        }
        return maxi;
        
    }
};
