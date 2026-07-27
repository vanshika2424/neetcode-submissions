class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
            vector<unordered_set<char>>rows(9);
            vector<unordered_set<char>>cols(9);
            vector<unordered_set<char>>box(9);
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    char ch=board[i][j];
                    if(ch == '.'){
                        continue;
                    }
                    if(rows[i].count(ch)) return false;
                    if(cols[j].count(ch)) return false;

                    rows[i].insert(ch);
                    cols[j].insert(ch);
                    int ind= (i/3)*3 + j/3;
                    if(box[ind].count(ch)) return false;
                    box[ind].insert(ch);

                }
            }
            return true;
    }
};
