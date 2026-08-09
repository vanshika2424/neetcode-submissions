class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(auto &it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int top=q.front();
            cnt++;
            q.pop();
            for(auto &adjnode:adj[top]){
                indegree[adjnode]--;
                if(indegree[adjnode]==0){
                    q.push(adjnode);
                }
            }

        }
        return (cnt==n);


        
    }
};
