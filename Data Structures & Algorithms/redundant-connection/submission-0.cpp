class DSU{
    vector<int>sz;
    vector<int>par;
public:
    DSU(int n){
        sz.resize(n+1,1);
        par.resize(n+1);
        for(int i=0;i<=n;i++){
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
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu(n);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            if(dsu.findUpar(u)==dsu.findUpar(v)){
                return it;
            }
            dsu.unite(u,v);
        }
        return {};
        
    }
        
    
};