class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // // for row
        // for(int i=0;i<9;i++){
        //     unordered_set<int> freq;
        //     for(int j=0;j<9;j++){
        //         if(board[i][j]=='.') continue;
        //         if(freq.find(board[i][j])!=freq.end()){
        //             return false;
        //         }
        //         freq.insert(board[i][j]);
        //     }
        // }
        // // for column
        // for(int j=0;j<9;j++){
        //     unordered_set<int> freq2;
        //     for(int i=0;i<9;i++){
        //         if(board[i][j]=='.') continue;
        //         if(freq2.find(board[i][j])!=freq2.end()){
        //             return false;
        //         }
        //         freq2.insert(board[i][j]);
        //     }
        // }
        // // for grid
        // for(int block = 0; block < 9; block++){
        //     unordered_set<int> freq3;
        //     for(int i = block / 3 * 3; i < block / 3 * 3 + 3; i++){
        //         for(int j = block % 3 * 3; j < block % 3 * 3 + 3; j++){
        //             if(board[i][j]!='.' && freq3.find(board[i][j])!=freq3.end()){
        //                 return false;
        //             }
        //             freq3.insert(board[i][j]);
        //         }
        //     }
        // }   
        // return true; // if all checks pass
        
        vector<set<int>> rows(9), cols(9), blocks(9);
        for(int i=0;i<9;i++){
            for(int j=0; j<9;j++){
                if(board[i][j]=='.') continue;
                int cur = board[i][j]-'0';
                if(rows[i].count(cur) || cols[j].count(cur) || blocks[(i/3)*3+j/3].count(cur)){
                    return false;
                }
                rows[i].insert(cur);
                cols[j].insert(cur);
                blocks[(i/3)*3+j/3].insert(cur);
            }
        }
        return true;
    }
};