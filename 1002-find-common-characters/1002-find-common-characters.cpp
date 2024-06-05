class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> res;
        vector<int> common(26,INT_MAX);
        
        for(auto x:words){
            vector<int> cnt(26,0);
            for(auto c:x){
                cnt[c-'a']++;
            }
            for(auto i=0;i<26;i++){
                common[i]=min(cnt[i],common[i]);
            }
        }
        
        for(auto i=0;i<26;i++){
            for(auto j=0;j<common[i];j++){
                res.push_back(string(1,i+'a'));
            }
        }
        return res;
    }
};