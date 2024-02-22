class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // for row
        for(int i=0;i<9;i++){
            unordered_set<int> freq;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.' && freq.find(board[i][j])!=freq.end()){
                    return false;
                }
                freq.insert(board[i][j]);
            }
        }
        // for column
        for(int j=0;j<9;j++){
            unordered_set<int> freq;
            for(int i=0;i<9;i++){
                if(board[i][j]!='.' && freq.find(board[i][j])!=freq.end()){
                    return false;
                }
                freq.insert(board[i][j]);
            }
        }
        // for grid
        for(int block = 0; block < 9; block++){
            unordered_set<int> freq;
            for(int i = block / 3 * 3; i < block / 3 * 3 + 3; i++){
                for(int j = block % 3 * 3; j < block % 3 * 3 + 3; j++){
                    if(board[i][j]!='.' && freq.find(board[i][j])!=freq.end()){
                        return false;
                    }
                    freq.insert(board[i][j]);
                }
            }
        }   
        return true; // if all checks pass
    }
};