class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>& state, stack<char>& st) {           
        if(state[node]==1){
            return false;
        }
        if(state[node]==2){
            return true;
        }
        state[node]=1;
        for(auto &adjnode:adj[node]){
        
            if(!dfs(adjnode,adj,state,st)){
                return false;
            }

            

        }
        state[node]=2;
        st.push(node+'a');
        return true;
        
    }
    string foreignDictionary(vector<string>& words) {
        int n=words.size();
        vector<vector<int>>adj(26);
        vector<int>state(26,0);
        vector<int>present(26,0);
        for(auto &it:words){
            for(char c:it){
                present[c-'a']=1;
            }
        }
        //build graph
        for(int i=0;i<n-1;i++){
            string w1=words[i];
            string w2=words[i+1];
            int ind=0;
            while(ind<w1.length() && ind<w2.length() && w1[ind]==w2[ind]){
                ind++;
            }
            //prefix check
            if(ind>=w2.length() && ind<w1.length()) return "";
            if(ind>=w1.length()) continue;
            int u=w1[ind]-'a';
            int v=w2[ind]-'a';
            adj[u].push_back(v);
        }

        //topological sort
        stack<char>st;
        for(int i=0;i<26;i++){
            if(present[i] && state[i]==0){
                if(!dfs(i,adj,state,st)){
                    return "";
                }
            }

        }
        
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            
        }
        return ans;

    }
};
