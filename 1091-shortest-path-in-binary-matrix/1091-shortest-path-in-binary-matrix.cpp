class Solution {
public:
    vector<vector<int>> direction{{1,0},{1,1},{0,1},{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1}};
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(n==0 || m==0 || grid[0][0]!=0){
            return -1;
        }
        auto isSafe=[&](int x, int y){
            return x>=0 && x<n && y>=0 && y<m;
        };
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        int levels = 0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto curr = q.front();
                q.pop();
                int x = curr.first;
                int y = curr.second;
                if(x==n-1 && y==m-1){
                    return levels+1;
                }
                for(auto dir: direction){
                    int x_ = x+dir[0];
                    int y_ = y+dir[1];
                    
                    if(isSafe(x_,y_) && grid[x_][y_]==0){
                        q.push({x_,y_});
                        grid[x_][y_]=1;
                    }
                }
                
            }
            levels++;
        }
        return -1;
    }
};