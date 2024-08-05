class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> freq;
        for(const auto& s: words1){
            freq[s]++;
        }
        for(const auto& t: words2){
            if(freq[t]<2){
                freq[t]--;
            }
        }
        int ans = 0;
        for(auto i:freq){
            if(i.second==0) ans++;
        }
        return ans;
    }
};