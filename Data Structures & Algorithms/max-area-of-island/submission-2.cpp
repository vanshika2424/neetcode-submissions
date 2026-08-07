class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&vis,int n,int m){
        vis[i][j]=1;
        int dr[4]={+1,-1,0,0};
        int dc[4]={0,0,+1,-1};
        int cnt=0;
        for(int r=0;r<4;r++){
            int row=i+dr[r];
            int col=j+dc[r];
            if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1 && vis[row][col]!=1){
                cnt+=1+dfs(row,col,grid,vis,n,m);
            }
        }
        return cnt;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,(vector<int>(m,0)));
        int maxarea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    
                    maxarea=max(maxarea,1+dfs(i,j,grid,vis,n,m));
                }
            }
        }
        return maxarea;
        
    }
};
