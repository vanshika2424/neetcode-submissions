class Solution {
public:
    string encode(vector<string>& strs) {
        int n=strs.size();
        string ans="";
        for(auto &s:strs){
            ans+=to_string(s.length());
            ans+='#';
            ans+=s;
        }
        return ans;

    }

    vector<string> decode(string s) {
        int n=s.length();
        vector<string>ans;
        int i=0;
        while(i<n){
            string l="";
            while(i<n && s[i]!='#'){
                l+=s[i];
                i++;
            }
            int j=stoi(l);
            
            ans.push_back(s.substr(i+1,j));
            i=i+j+1;
        }
        return ans;

    }
};
