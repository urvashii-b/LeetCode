class Solution {
private:
    void DFS(vector<vector<int>>& grid, vector<vector<bool>> &vis, int i, int j, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0 || vis[i][j]==true){
            return;
        }
        vis[i][j]=true;
        DFS(grid,vis,i+1,j,n,m);
        DFS(grid,vis,i-1,j,n,m);
        DFS(grid,vis,i,j+1,n,m);
        DFS(grid,vis,i,j-1,n,m);
    }
    int numOfIslands(vector<vector<int>>& grid, int n, int m){
        int islands = 0;
        vector<vector<bool>> vis(n, vector<bool> (m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    DFS(grid,vis,i,j,n,m);
                    islands++;
                }
            }
        }
        return islands;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int islands = numOfIslands(grid, n, m);
        if(islands>1 || islands ==0){
            return 0;
        }else{
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1){
                        grid[i][j]=0;
                        islands = numOfIslands(grid, n, m);
                        if(islands>1 || islands ==0){
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