class Solution {
private:
    void DFS(int row, int col, vector<vector<bool>> &vis, vector<vector<int>>& grid, int n, int m){
        if(row<0 || col<0 || row>=n || col>=m || vis[row][col]==true || grid[row][col]==0){
            return;
        }
        vis[row][col]=true;
        DFS(row+1,col,vis,grid, n, m);
        DFS(row-1,col,vis,grid, n, m);
        DFS(row,col+1,vis,grid, n, m);
        DFS(row,col-1,vis,grid, n, m);
    }
    
    int numberOfIslands(vector<vector<int>>& grid, int n, int m){
        int islands = 0;
        vector<vector<bool>> vis(n, vector<bool> (m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    DFS(i,j,vis,grid, n, m);
                    islands++;
                }
            }
        }
        return islands;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int islands = numberOfIslands(grid,n,m);
        if(islands>1 || islands == 0){
            return 0;
        }else{
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1){
                        grid[i][j]=0;
                        
                        islands = numberOfIslands(grid,n,m);
                        if(islands==0 || islands>1){
                            return 1;
                        }
                        grid[i][j]=1;
                    }
                }
            }
        }
        return 2;
    }
};