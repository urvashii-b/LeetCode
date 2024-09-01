class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &vis){
        int n = grid.size(), m=grid[0].size();
        vis[i][j]=1;
        for(auto& dir: directions){
            int newI = i+dir[0];
            int newJ = j+dir[1];
            
            if(newI>=0 && newI<n && newJ>=0 && newJ<m && !vis[newI][newJ] && grid[newI][newJ]==1){
                dfs(newI,newJ,grid,vis);
            }
        }
    }
public:
    vector<vector<int>> directions{{-1,0},{1,0},{0,1},{0,-1}};
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        // 1st row and last row
        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && !vis[0][j]){
                dfs(0,j,grid,vis);
            }
            if(grid[n-1][j]==1 && !vis[n-1][j]){
                dfs(n-1,j,grid,vis);
            }
        }
        // 1st col and last col
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !vis[i][0]){
                dfs(i,0,grid,vis);
            }
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                dfs(i,m-1,grid,vis);
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};