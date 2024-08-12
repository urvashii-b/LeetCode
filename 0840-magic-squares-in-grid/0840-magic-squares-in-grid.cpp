class Solution {
private:
    bool isMagic(vector<vector<int>>& grid, int r, int c){
        unordered_set<int> st;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int num = grid[r+i][c+j];
                if(num<1 || num>9 || st.count(num)){
                    return false;
                }else{
                    st.insert(num);
                }
            }
        }
        int SUM = grid[r][c]+grid[r][c+1]+grid[r][c+2];
        for(int i=0;i<3;i++){
            if(grid[r+i][c]+grid[r+i][c+1]+grid[r+i][c+2]!=SUM){    // row sum
                return false;
            }
            if(grid[r][c+i]+grid[r+1][c+i]+grid[r+2][c+i]!=SUM){    // col sum
                return false;
            }
        }
        if(grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2]!=SUM){    // diagonal sum
            return false;
        }
        if(grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c]!=SUM){    // anti-diagonal sum
            return false;
        }
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                if(isMagic(grid,i,j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};