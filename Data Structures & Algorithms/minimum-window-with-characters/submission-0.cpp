class Solution {
public:
    string minWindow(string s, string t) {
        int m=t.length();
        int n=s.length();
        vector<int>hash(256,0);
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }
        int l=0;
        int cnt=0;
        int minlen=INT_MAX;
        int sind=-1;
        for(int r=0;r<n;r++){
            if(hash[s[r]]>0){
                cnt++;
            }
            hash[s[r]]--;
            while(cnt==m){
                hash[s[l]]++;
                if(r-l+1<minlen){
                    sind=l;
                    minlen=r-l+1;

                }
                if(hash[s[l]]>0){
                    cnt--;
                }
                l++;

            }

        }
        if(sind==-1){
            return "";
        }
        return s.substr(sind, minlen);
        
    }
};
