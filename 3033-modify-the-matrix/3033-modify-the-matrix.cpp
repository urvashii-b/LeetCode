class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> ans(matrix);
        for(int c=0;c<m;c++){
            int maxVal = INT_MIN;
            for(int r=0;r<n;r++){
                maxVal = max(maxVal, matrix[r][c]);
            }
            for(int r=0;r<n;r++){
                if(matrix[r][c]==-1){
                    ans[r][c]=maxVal;
                }
            }
        }
        return ans;
    }
};