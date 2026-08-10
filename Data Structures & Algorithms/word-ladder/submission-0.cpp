class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        set<string>s;
        for(int i=0;i<n;i++){
            s.insert(wordList[i]);

        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        int minlen=INT_MAX;
        while(!q.empty()){
            string word=q.front().first;
            int len=q.front().second;
            q.pop();
            if(word==endWord){
                minlen=min(minlen,len); 
                continue;
            }
            for(int i=0;i<word.length();i++){
                char ch=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(s.find(word)!=s.end()){
                        q.push({word,len+1});
                        s.erase(word);
                    }

                }
                word[i]=ch;
            }
            
        }
        return (minlen==INT_MAX)?0:minlen;
        
    }
};
