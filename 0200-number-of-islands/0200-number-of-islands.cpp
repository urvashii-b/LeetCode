#include<bits/stdc++.h>
class Solution {
private:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>> &vis, int i, int j, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0' || vis[i][j]){
            return;
        }
        vis[i][j]=true;
        dfs(grid,vis,i+1,j,n,m);
        dfs(grid,vis,i-1,j,n,m);
        dfs(grid,vis,i,j+1,n,m);
        dfs(grid,vis,i,j-1,n,m);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()){
            return 0;
        }
        int n = grid.size(), m = grid[0].size(), islands = 0;
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(grid,vis,i,j,n,m);
                    islands++;
                }
            }
        }
        return islands;
    }
};
