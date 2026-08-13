class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>time(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});
        time[0][0]=grid[0][0];
        int dr[4]={+1,-1,0,0};
        int dc[4]={0,0,+1,-1};
        while(!pq.empty()){
            int t=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(i==n-1 && j==n-1) break;
            for(int r=0;r<4;r++){
                int row=i+dr[r];
                int col=j+dc[r];
                
                if(row>=0 && row<n && col>=0 && col<n && max(t,grid[row][col])<time[row][col]){
                    time[row][col]=max(t,grid[row][col]);
                    pq.push({time[row][col],{row,col}});
                }
            }
            

        }
        return time[n-1][n-1];
        
    }
};
