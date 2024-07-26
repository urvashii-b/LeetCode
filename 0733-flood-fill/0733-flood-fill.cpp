class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int newColour, int delRow[], int delCol[], int initialColour){
        ans[row][col] = newColour;
        int m = image.size(), n = image[0].size();
        for(int i=0;i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && ans[nrow][ncol]!=newColour && ans[nrow][ncol]==initialColour){
                dfs(nrow,ncol,ans,image,newColour,delRow,delCol,initialColour);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColour = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[]={-1,0,+1,0};
        int delCol[]={0,-1,0,+1};
        dfs(sr,sc,ans,image, color, delRow, delCol, initialColour);
        return ans;
    }
};