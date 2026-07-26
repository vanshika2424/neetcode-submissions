class Solution {
public:
   
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // unordered_map<string,vector<string>>m;
        // for(int i=0;i<strs.size();i++){
        //     string key=strs[i];
        //     sort(key.begin(),key.end());
        //     m[key].push_back(strs[i]);
        // }
        // vector<vector<string>>ans;
        // for(auto &it:m){
        //     ans.push_back(it.second);
            
        // }
        // return ans;
        unordered_map<string,vector<string>>m;
        for(string s:strs){
            vector<int>hash(26,0);
            for(char c:s){
                hash[c-'a']++;
            }
            string key;
            for(auto i:hash){
                key+='#'+to_string(i);

            }
            m[key].push_back(s);

        }
        vector<vector<string>>ans;
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
        
        
       
        
        
    }
};
