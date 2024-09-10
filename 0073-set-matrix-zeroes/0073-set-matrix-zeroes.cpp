class Solution {
private:
    void markRow(int i, int j, int n, int m, vector<vector<int>>& matrix){
        for(int j=0; j<m; j++){
            if(matrix[i][j]!=0){
                matrix[i][j] = -1;
            }
        }
    }
    
    void markCol(int i, int j, int n, int m, vector<vector<int>>& matrix){
        for(int i=0; i<n; i++){
            if(matrix[i][j]!=0){
                matrix[i][j] = -1;
            }
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /*
        Brute force
        
        int n = matrix.size(), m = matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    markRow(i,j,n,m,matrix);
                    markCol(i,j,n,m,matrix);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==-1){
                    matrix[i][j]=0;
                }
            }
        }
        */
        int n = matrix.size(), m = matrix[0].size();
        int row[201]={0};
        int col[201]={0};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(row[i]==1 || col[j]==1){
                    matrix[i][j]=0;
                }
            }
        }
    }    
};