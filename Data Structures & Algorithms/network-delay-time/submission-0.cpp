class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &it:times){
            int u=it[0];
            int v=it[1];
            int t=it[2];
            adj[u].push_back({v,t});

        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        vector<int>time(n+1,INT_MAX);
        time[k]=0;
        while(!pq.empty()){
            int t=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &it:adj[node]){
                int ti=it.second;
                int adjnode=it.first;
                if(t+ti<time[adjnode]){
                    time[adjnode]=ti+t;
                    pq.push({time[adjnode],adjnode});
                }
            }
        }
        int mintime=0;
        for(int i=1;i<=n;i++){
            if(time[i]==INT_MAX) return -1;
            mintime=max(mintime,time[i]);
        }
        return mintime;
        
    }
};
