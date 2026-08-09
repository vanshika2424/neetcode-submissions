class Solution {
public:
    bool dfs(int node,int par,vector<int>& vis,vector<vector<int>>& adj){
        vis[node]=1;
        for(auto &adjnode:adj[node]){
            if(!vis[adjnode]){
                if(!dfs(adjnode,node,vis,adj)) return false;
            }
            else if(adjnode!=par){
                return false;
            }
        }
        return true;

    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);

        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(!dfs(i,-1,vis,adj)) return false;
                cnt++;
            }

        
        }
        return (cnt==1);
    }
};
