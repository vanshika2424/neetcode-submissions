class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        int time=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int dr[4]={+1,-1,0,0};
        int dc[4]={0,0,-1,+1};
        while(!q.empty()){
            int s=q.size();

            for(int i=0;i<s;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int r=0;r<4;r++){
                    int row=x+dr[r];
                    int col=y+dc[r];
                    if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1){
                        q.push({row,col});
                        grid[row][col]=2;
                    }
                }
                
            }
            if(!q.empty()) time++;

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};
