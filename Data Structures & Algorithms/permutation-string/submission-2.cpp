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
        unordered_map<char,int>m2;
        for(int i=0;i<m;i++){
            m1[s1[i]]++;
        }
        int l=0;
        for(int r=0;r<n;r++){
            m2[s2[r]]++;
            while(r-l+1>m){
                m2[s2[l]]--;
                if(m2[s2[l]]==0){
                    m2.erase(s2[l]);
                }
                l++;
                
            }  
            if(checkifpermutation(m1,m2)){
                return true;

            }          
        }
        return false;
        
    }
};
