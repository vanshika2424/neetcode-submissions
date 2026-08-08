class Solution {
public:
    int n;
    int m;
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>>& vis){
        vis[i][j]=1;
        int dr[4]={+1,-1,0,0};
        int dc[4]={0,0,+1,-1};
        for(int r=0;r<4;r++){
            int row=i+dr[r];
            int col=j+dc[r];
            if(row>=0 && row<n && col>=0 && col<m && board[row][col]=='O' && !vis[row][col]){
                dfs(row,col,board,vis);
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(i,0,board,vis);
            }
        }
        for(int i=0;i<m;i++){
            if(board[n-1][i]=='O' && !vis[n-1][i]){
                dfs(n-1,i,board,vis);
            }
        }
        for(int i=n-1;i>=0;i--){
            if(board[i][m-1]=='O' && !vis[i][m-1]){
                dfs(i,m-1,board,vis);
            }
        }
        for(int i=m-1;i>=0;i--){
            if(board[0][i]=='O' && !vis[0][i]){
                dfs(0,i,board,vis);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
        
    }
};
