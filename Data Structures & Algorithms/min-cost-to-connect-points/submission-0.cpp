class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>>pq;
        pq.push({0,points[0]});
        set<vector<int>>vis;
        for(int i=0;i<n;i++){
            vis.insert(points[i]);
        }
        
        int sum=0;
        while(!pq.empty()){
            int edge=pq.top().first;
            vector<int>point=pq.top().second;
            pq.pop();
            int u=point[0];
            int v=point[1];
            if(!vis.count(point)) continue;
            sum+=edge;
            vis.erase(point);
            
            for(int i=0;i<n;i++){
                if(vis.count(points[i])){
                    int u2=points[i][0];
                    int v2=points[i][1];
                    int e=abs(u-u2)+abs(v-v2);
                    pq.push({e,points[i]});
                }
            }

        }
        return sum;
        
    }
};
