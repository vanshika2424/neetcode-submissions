class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<int>>& heights,int n,int m){
        vis[i][j]=1;
        
        int dr[4]={+1,-1,0,0};
        int dc[4]={0,0,+1,-1};
        for(int r=0;r<4;r++){
            int row=i+dr[r];
            int col=j+dc[r];
            if(row>=0 && row<n && col>=0 && col<m && heights[row][col]>=heights[i][j] && !vis[row][col] ){
                dfs(row,col,vis,heights,n,m);
            }

        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>pacific(n,vector<int>(m,0));
        vector<vector<int>>atlantic(n,vector<int>(m,0));

        for(int i=0;i<m;i++){
            dfs(0,i,pacific,heights,n,m);
        }
        for(int i=1;i<n;i++){
            dfs(i,0,pacific,heights,n,m);
        }
        for(int i=0;i<m;i++){
            dfs(n-1,i,atlantic,heights,n,m);
        }
        for(int i=0;i<n-1;i++){
            dfs(i,m-1,atlantic,heights,n,m);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]==1 && atlantic[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
        
    }
};
