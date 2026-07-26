class Solution {
public:
    string encode(vector<string>& strs) {
        int n=strs.size();
        string s="";
        for(int i=0;i<n;i++){
            int l=strs[i].length();
            for(int j=0;j<l;j++){
                int ascii=(unsigned char)strs[i][j];
                s+= to_string(ascii)  + '#';

            }
            s+=',';

        }
        return s;

    }

    vector<string> decode(string s) {
        int n=s.length();
        vector<string>ans;
        int i=0;
        while(i<n){
            string word="";
            while(i<n && s[i]!=','){
                int num=0;
                while(i<n && s[i]!='#'){
                    num = num * 10 + (s[i]-'0');
                    i++;
                }
                word+=(char) num;
                i++;

            }
            ans.push_back(word);
            i++;

        }
        return ans;

    }
};
