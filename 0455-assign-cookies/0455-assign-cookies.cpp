class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int children = g.size(), cookies = s.size(), l = 0, r = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(l<children && r<cookies){
            if(g[l]<=s[r]){
                l++;
            }
            r++;
        }
        return l;
    }
};