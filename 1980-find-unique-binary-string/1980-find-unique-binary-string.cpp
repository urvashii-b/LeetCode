class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // Cantor's Diagonal Argument
        int n = nums.size();
        string ans = "";
        for(int i=0;i<n;i++){
            char cur = nums[i][i];
            ans+= cur=='0'? '1':'0';
        }
        return ans;
    }
};