class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int maxlen=0;
        unordered_set<char>st;
        int l=0;
        for(int r=0;r<n;r++){
            while(st.count(s[r])){
                st.erase(s[l]);
                l++;
                
            }
            maxlen=max(maxlen,r-l+1);
            st.insert(s[r]);
        }   
        return maxlen;   
    }
};
