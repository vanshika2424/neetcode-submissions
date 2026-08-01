class Solution {
public:
    // bool checkifpermutation(unordered_map<char,int>&m1,unordered_map<char,int>&m2){
    //     if(m1.size()!=m2.size()) return false;
    //     for(auto &it:m1){
    //         if(m2[it.first]!=it.second){
    //             return false;

    //         }
    //     }
    //     return true;
    // }
    bool checkifpermutation(vector<int>&freq){
        for(int i=0;i<26;i++){
            if(freq[i]!=0) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();
        vector<int>freq(26,0);
        // unordered_map<char,int>m1;
        // unordered_map<char,int>m2;
        for(int i=0;i<m;i++){
            freq[s1[i]-'a']++;
        }
        int l=0;
        for(int r=0;r<n;r++){
            // m2[s2[r]]++;
            freq[s2[r]-'a']--;
            while(r-l+1>m){
                freq[s2[l]-'a']++;
                l++;
                
            }  
            if(checkifpermutation(freq)){
                return true;

            }    
            // for(int i=0;i<26;i++){
            //     if(freq[i]!=0) 
            // }      
        }
        return false;
        
    }
};
