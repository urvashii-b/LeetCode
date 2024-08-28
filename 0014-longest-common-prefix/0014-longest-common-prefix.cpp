class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size();
        for(int i=0;i<strs[0].length();i++){
            char c = strs[0][i];
            bool match = true;
            for(int j=1;j<n;j++){
                if(c!=strs[j][i] || strs[j].length()<i){
                    match = false;
                    break;
                }
            }
            if(match==false){
                break;
            }else{
                ans.push_back(c);
            }
        }
        return ans;
    }
};