class Solution {
private:
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>> &vis, int delRow[], int delCol[], int n, int m){
        vis[i][j]=1;
        for(int x=0;x<4;x++){
            int newI = i+delRow[x];
            int newJ = j+delCol[x];
            
            if(newI>=0 && newI<n && newJ>=0 && newJ<m && !vis[newI][newJ] && board[newI][newJ]=='O'){
                dfs(newI,newJ,board,vis,delRow,delCol,n,m);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        int delRow[]={0,-1,0,1};
        int delCol[]={-1,0,1,0};
        vector<vector<int>> vis(n, vector<int> (m,0));
        
        // traverse 1st and last row
        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0, j, board, vis, delRow, delCol, n, m);
            }
            
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1, j, board, vis, delRow, delCol, n, m);
            }
        }
        // traverse 1st and last column
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i, 0, board, vis, delRow, delCol, n, m);
            }
            
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i, m-1, board, vis, delRow, delCol, n, m);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};