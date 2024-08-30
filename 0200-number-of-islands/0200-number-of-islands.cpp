#include<bits/stdc++.h>
class Solution {
private:
    bool isInvalid(int i, int j, vector<vector<char>>& grid, vector<vector<bool>> &vis, int n, int m){
        return (i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0' || vis[i][j]);
    }
    void dfs(int n, int m, vector<vector<char>>& grid, vector<vector<bool>> &vis, int i, int j){
        if(isInvalid(i,j,grid,vis,n,m)){
            return;
        }
        vis[i][j]=true;
        dfs(n,m,grid,vis,i+1,j);
        dfs(n,m,grid,vis,i-1,j);
        dfs(n,m,grid,vis,i,j+1);
        dfs(n,m,grid,vis,i,j-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()){
            return 0;
        }
        int n = grid.size(), m = grid[0].size();
        int islands = 0;
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(n,m,grid,vis,i,j);
                    islands++;
                }
            }
        }
        return islands;
    }
};
