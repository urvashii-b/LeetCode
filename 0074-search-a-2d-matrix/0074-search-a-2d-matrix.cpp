class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = n*m-1, row, col, mid;
        while(low<=high){
            mid = (low+high)/2;
            row = mid/m, col = mid%m; // flattening into 1D + binary search
            if(matrix[row][col]==target){
                return true;
            }else if(matrix[row][col]<target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return false;
    }
};