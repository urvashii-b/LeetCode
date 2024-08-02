class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int> mpp1, mpp2;
        for(auto c:s){
            mpp1[c]++;
        }
        int cnt = 0, n = s.length();
        for(int i=0;i<n;i++){
            mpp1[s[i]]--;
            if(mpp1[s[i]]==0) mpp1.erase(s[i]);
            mpp2[s[i]]++;
            if(mpp2.size()==mpp1.size()) cnt++;
        }
        return cnt;
    }
};