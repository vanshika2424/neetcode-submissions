class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int r=0;r<9;r++){
            unordered_set<char>s;

            for(int c=0;c<9;c++){
                char ch=board[r][c];
                if(ch=='.'){
                    continue;
                }
                if(s.count(ch)){
                    return false;
                }
                s.insert(ch);

            }
        }

        for(int c=0;c<9;c++){
            unordered_set<char>s;
            for(int r=0;r<9;r++){
                char ch=board[r][c];
                if(ch=='.'){
                    continue;
                }
                if(s.count(ch)){
                    return false;
                }
                s.insert(ch);

            }
        }

       
        for(int r=0;r<9;r+=3){
            for(int c=0;c<9;c+=3){

                unordered_set<char>s;
                for(int i=r;i<r+3;i++){
                    for(int j=c;j<c+3;j++){
                        char ch=board[i][j];

                        if(ch=='.') continue;
                        if(s.count(ch)) return false;

                        s.insert(ch);
                    }
                }

            }
        }
        return true;
        
        


        
    }
};
