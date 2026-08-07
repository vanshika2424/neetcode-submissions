class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        int time=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        int dr[4]={+1,-1,0,0};
        int dc[4]={0,0,-1,+1};
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int t=q.front().second;
            time=max(t,time);
            q.pop();
            for(int r=0;r<4;r++){
                int row=x+dr[r];
                int col=y+dc[r];
                if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1){
                    q.push({{row,col},t+1});
                    grid[row][col]=2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};
