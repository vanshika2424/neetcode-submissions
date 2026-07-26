class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }

            }
        }
        int drow[4]={1,-1,0,0};
        int dcol[4]={0,0,1,-1};
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int dist=q.front().second;
            
            q.pop();
            grid[i][j]=dist;
            
            
            for(int r=0;r<4;r++){
                int row=i+drow[r];
                int col=j+dcol[r];
                if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==2147483647 && vis[row][col]==0){
                    
                    q.push({{row,col},dist+1});
                    vis[row][col]=1;
                }

            }
        }
        

        
    }
};
