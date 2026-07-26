class Solution {
public:
    int bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&vis){
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        int drow[4]={1,-1,0,0};
        int dcol[4]={0,0,-1,1};
        int count=1;

        while(!q.empty()){
            int x=q.front().first;
            
            
            int y=q.front().second;
           
            q.pop();
            for(int r=0;r<4;r++){
                int row=x+drow[r];
                cout<<row<<" ";
                int col=y+dcol[r];
                cout<<col<<endl;
                if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size() && grid[row][col]==1 && vis[row][col]==0){
                    vis[row][col]=1;
                    count++;
                    q.push({row,col});
                }


            }
            
        }
       
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,(vector<int>(m,0)));
        int maxarea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    
                    maxarea=max(maxarea,bfs(i,j,grid,vis));
                }
            }
        }
        return maxarea;
        
    }
};
