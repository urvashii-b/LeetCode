class Solution {
private:
    void dfs(int initialColor, int newColor, int x, int y, int delRow[], int delCol[], vector<vector<int>>& image, vector<vector<int>>& ans){
        ans[x][y]=newColor;
        int n = image.size(), m = image[0].size();
        for(int i=0; i<4; i++){
            int nrow = x+delRow[i];
            int ncol = y+delCol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initialColor && ans[nrow][ncol]!=newColor){
                dfs(initialColor, newColor, nrow, ncol, delRow, delCol, image, ans);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColour = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[]={-1,0,1,0};
        int delCol[]={0,-1,0,1};
        dfs(initialColour, color, sr, sc, delRow, delCol, image, ans);
        return ans;
    }
};