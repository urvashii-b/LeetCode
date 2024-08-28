class Solution {
private:
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    bool solve(vector<vector<char>>& board, string &word, int i, int j, int index, int n, int m){
        if(index==word.length()){
            return true;
        }
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='$'){
            return false;
        }
        if(board[i][j]!=word[index]) return false;
        char temp = board[i][j];
        board[i][j]='$';
        for(auto &it: directions){
            int newI = it[0]+i;
            int newJ = it[1]+j;
            
            if(solve(board,word,newI,newJ,index+1,n,m)){
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && solve(board,word,i,j, 0,n,m)){
                    return true;
                }
            }
        }
        return false;
    }
};