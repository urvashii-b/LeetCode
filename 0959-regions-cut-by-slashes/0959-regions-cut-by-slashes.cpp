class Solution {
private:
    void dfs(vector<vector<int>> &res, vector<vector<bool>> &vis, int i, int j, int x, int y){
        if(i<0 || j<0 || i>=x || j>=y || res[i][j]==1 || vis[i][j]==true){
            return;
        }
        vis[i][j]=true;
        dfs(res,vis,i+1,j,x,y);
        dfs(res,vis,i-1,j,x,y);
        dfs(res,vis,i,j+1,x,y);
        dfs(res,vis,i,j-1,x,y);
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size();
        int regions = 0;
        vector<vector<int>> res(n*3,vector<int> (m*3, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='\\'){
                    res[i*3][j*3]=1;
                    res[i*3+1][j*3+1]=1;
                    res[i*3+2][j*3+2]=1;
                }else if(grid[i][j]=='/'){
                    res[i*3][j*3+2]=1;
                    res[i*3+1][j*3+1]=1;
                    res[i*3+2][j*3]=1;
                }
            }
        }
        vector<vector<bool>> vis(n*3, vector<bool> (m*3, false));
        int x = res.size(), y = res[0].size();
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(res[i][j]==0 && !vis[i][j]){
                    dfs(res,vis,i,j,x,y);
                    regions++;
                }
            }
        }
        return regions;
    }
};