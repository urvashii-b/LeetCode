class Solution {
/*
1. BRUTE FORCE
private:
    void markRow(vector<vector<int>>& matrix, int n, int m, int i){
        for(int j=0; j<m; j++){
            if(matrix[i][j]!=0){
                matrix[i][j]=-1;
            }
        }
    }
    
    void markCol(vector<vector<int>>& matrix, int n, int m, int j){
        for(int i=0; i<n; i++){
            if(matrix[i][j]!=0){
                matrix[i][j]=-1;
            }
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        int m = (int)matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    markRow(matrix, n, m, i);
                    markCol(matrix, m, n, j);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==-1){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

2. BETTER
*/
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row[200]={0};
        int col[200]={0};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( row[i] || col[j]){
                    matrix[i][j]=0;
                }
            }
        }
        
    }
};