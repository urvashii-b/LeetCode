class Solution {
public:
    vector<vector<int>> directions={{0,-1},{0,1},{1,0},{-1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> res(n, vector<int> (m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    res[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int, int> P = q.front();
            q.pop();
            
            int u = P.first;
            int v = P.second;
            
            for(auto& dir: directions){
                int new_u = u+dir[0];
                int new_v = v+dir[1];
                if(new_u>=0 && new_u<n && new_v>=0 && new_v<m && res[new_u][new_v]==-1){
                    res[new_u][new_v] = res[u][v]+1;
                    q.push({new_u, new_v});
                }
            }
        }
        return res;
    }
};