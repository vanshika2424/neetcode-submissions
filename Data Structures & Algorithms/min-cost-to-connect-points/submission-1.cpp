class DSU{
    vector<int>sz;
    vector<int>par;
public:
    DSU(int n){
        sz.resize(n,1);
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }

    int findUpar(int x){
        if(x==par[x]){
            return x;
        }
        return par[x]=findUpar(par[x]);
    }

    void unite(int u,int v){
        int up=findUpar(u);
        int vp=findUpar(v);
        if(up==vp) return;
        if(sz[up]<=sz[vp]){
            par[up]=vp;
            sz[vp]+=sz[up];
        }
        else{
            par[vp]=up;
            sz[up]+=sz[vp];
        }

    }
};



class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<int>>edges;
        for(int i=0;i<n;i++){
            int u1=points[i][0];
            int v1=points[i][1];
            for(int j=i+1;j<n;j++){
                int u2=points[j][0];
                int v2=points[j][1]; 
                edges.push_back({abs(u1-u2)+abs(v1-v2),i,j});
            }
        }
        sort(edges.begin(),edges.end());
        DSU dsu(n);
        int sum=0;
        int edgecnt=0;
        for(int i=0;i<edges.size();i++){
            int e=edges[i][0];
            int u=edges[i][1];
            int v=edges[i][2];
            
            if(dsu.findUpar(u)!=dsu.findUpar(v)){
                dsu.unite(u,v);
                sum+=e;
                edgecnt++;
            }
            if(edgecnt==n-1) break;
        }
        return sum;
        
    }
};
