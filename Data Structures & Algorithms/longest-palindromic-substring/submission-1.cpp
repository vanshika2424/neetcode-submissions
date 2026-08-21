class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int maxlen=INT_MIN;
        int st;
        for(int i=0;i<n;i++){
            int l=i;
            int r=i;
            
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>maxlen){
                    st=l;
                    maxlen=r-l+1;
                }
                l--;
                r++;
            }

            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>maxlen){
                    st=l;
                    maxlen=r-l+1;
                }
                l--;
                r++;
            }

        }
        return (maxlen==INT_MIN)? "":s.substr(st,maxlen);
        
        
    }
};
