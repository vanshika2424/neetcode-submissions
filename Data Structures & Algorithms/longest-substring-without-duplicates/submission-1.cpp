class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int maxlen=0;
        unordered_map<char,int>m;
        int l=0;
        for(int r=0;r<n;r++){
            if(m.find(s[r])!=m.end() && m[s[r]]>=l){
                l=m[s[r]]+1;
            }
            maxlen=max(maxlen,r-l+1);
            m[s[r]]=r;
        }   
        return maxlen;   
    }
};
