class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int maxlen=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>m;
            for(int j=i;j<n;j++){
                if(m.count(s[j])){
                    break;
                }
                maxlen=max(maxlen,j-i+1);
                m[s[j]]++;

            }
        }  
        return maxlen;      
    }
};
