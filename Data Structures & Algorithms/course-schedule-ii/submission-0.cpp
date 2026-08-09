class Solution {
public:
    stack<int>s;
    bool dfs(int node,vector<int>& vis,vector<int>& pathvis,vector<vector<int>>& adj){
        vis[node]=1;
        pathvis[node]=1;
        for(auto &adjnode:adj[node]){
            if(!vis[adjnode]){
                if(!dfs(adjnode,vis,pathvis,adj)) return false;
            }
            else if(pathvis[adjnode]){
                return false;
            }
        }
        pathvis[node]=0;
        s.push(node);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        for(auto &it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(!dfs(i,vis,pathvis,adj)) return {};
            }
        }

        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
        
    }
};
