class Solution {
public:
    bool checkifpermutation(unordered_map<char,int>&m1,unordered_map<char,int>&m2){
        if(m1.size()!=m2.size()) return false;
        for(auto &it:m1){
            if(m2[it.first]!=it.second){
                return false;

            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();
        unordered_map<char,int>m1;
        for(int i=0;i<m;i++){
            m1[s1[i]]++;
        }
        for(int i=0;i<n;i++){
            unordered_map<char,int>m2;
            for(int j=i;j<n;j++){
                m2[s2[j]]++;
                if(checkifpermutation(m1,m2)){
                    return true;
                }
                
            }
        }
        return false;
        
    }
};
