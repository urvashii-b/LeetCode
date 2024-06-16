class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ansRow;
        long long ans = 1;
        ansRow.push_back(ans);
        rowIndex++;
        for(int col=1;col<rowIndex;col++){
            ans *= (rowIndex-col);
            ans /= col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }
};