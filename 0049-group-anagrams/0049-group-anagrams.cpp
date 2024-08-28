class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        for(auto &word: strs){
            string s = word;
            sort(word.begin(),word.end());
            mpp[word].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto &it: mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};