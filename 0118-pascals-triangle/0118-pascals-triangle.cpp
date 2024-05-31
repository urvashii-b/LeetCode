class Solution {
private:
    vector<int> generateRow(int row){
        vector<int> temp;
        long long ans = 1;
        temp.push_back(ans);
        for(int i=1;i<row;i++){
            ans = ans * (row-i);
            ans = ans/(i);
            temp.push_back(ans);
        }
        return temp;
    }  
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};