class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mpp(128,0);
        for(auto c: t){
            mpp[c]++;
        }
        int begin = 0, end = 0, cnt = t.size(), d = INT_MAX, head = 0;
        while(end<s.size()){
            if(mpp[s[end++]]-->0){ 
            /* move end pointer fwd, 
            dec mpp[s[end]] by 1 if found & 
            dec counter if found in mpp {part of t}
            */
                cnt--;
            }
            while(cnt==0){ // valid --> found all t chars in s
                if(end-begin<d){
                    d= end-( head= begin); // update d if len of window is min
                }
                if(mpp[s[begin++]]++==0){ // occurence becomes 0, then inc counter as it misses a char from t
                    cnt++;
                }
            }   
        }
        return d==INT_MAX?"":s.substr(head,d);
    }
};