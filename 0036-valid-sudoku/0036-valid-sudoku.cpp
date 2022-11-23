class Solution {
public:
   bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int>row[9],col[9];
        unordered_map<char,int>mat[3][3];
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                
                char t=board[i][j];
                if(t=='.')
                    continue;
                if(row[i].find(t)!=row[i].end())
                    return false;
                if(col[j].find(t)!=col[j].end())
                    return false;
                if(mat[i/3][j/3].find(t)!=mat[i/3][j/3].end())
                    return false;
                row[i][t]++;
                col[j][t]++;
                mat[i/3][j/3][t]++;
            }
        }
        return true;
    }
};