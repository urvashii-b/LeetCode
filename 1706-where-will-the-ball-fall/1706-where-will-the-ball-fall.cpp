class Solution {
private: 
    
    bool valid(int row, int col, int n, int m){
        return (row>=0 && col>=0 && row<n && col<m);
    }
    
    int solve(int n, int m, vector<vector<int>>& dp, vector<int>& ans, vector<vector<int>>& grid, int row, int col){
        if(row==n){
            return col;
        }
        if(valid(row, col, n, m)){
            if(grid[row][col]==1 && valid(row,col+1,n,m) && grid[row][col+1]==1){
                if(dp[row+1][col+1]!=0){
                    return dp[row+1][col+1];
                }else{
                    return dp[row+1][col+1]= solve(n,m,dp,ans,grid,row+1,col+1);
                }
            }
            if(grid[row][col]==-1 && valid(row,col-1,n,m) && grid[row][col-1]==-1){
                if(dp[row+1][col-1]!=0){
                    return dp[row+1][col-1];
                }else{
                    return dp[row+1][col-1]= solve(n,m,dp,ans,grid,row+1,col-1);
                }
            }
        }
        return -1;
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int nrow = grid.size();
        int ncol = grid[0].size();
        vector<int> ans(ncol,0);
        vector<vector<int>> dp(101, vector<int>(101,0));
        for(int i=0;i<ncol;i++){
            ans[i]= solve(nrow, ncol, dp, ans, grid, 0, i);
        }
        return ans;
    }
};