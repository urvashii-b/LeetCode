class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int n = grid.size(), m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int vis[n][m];
        int cntFresh = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});  // rotten
                    vis[i][j]=1;
                }else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1) cntFresh++;
            }
        }
        int cnt=0, tm = 0;
        int drow[]={0,-1,0,1};
        int dcol[]={1,0,-1,0};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=1 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=1;
                    cnt++;
                }
            }
        } 
        if(cnt!=cntFresh) return -1;
        return tm; 
    }
};