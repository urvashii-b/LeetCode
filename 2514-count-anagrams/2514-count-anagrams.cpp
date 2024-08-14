class Solution {
public:
    const int mod = 1e9+7;
    vector<long long> fact, invfact;
    long long modPow(long long base, long long exp, int mod){
        long long res = 1;
        while(exp>0){
            if(exp%2==1){
                res = (res*base)%mod;
            }
            base = (base*base)%mod;
            exp/=2;
        }
        return res;
    }
    void getFact(int maxN){
        fact.resize(maxN+1);
        invfact.resize(maxN+1);
        fact[0]=invfact[0]=1;
        for(int i=1;i<=maxN;i++){
            fact[i]=(fact[i-1]*i)%mod;
        }
        invfact[maxN]=modPow(fact[maxN],mod-2,mod);
        for(int i=maxN-1;i>=0;i--){
            invfact[i]=(invfact[i+1]*(i+1))%mod;
        }
    }
    int countAnagrams(string s) {
        int maxlength = s.length();
        getFact(maxlength);
        vector<string> words;
        string word;
        for(char c:s){
            if(c==' '){
                if(!word.empty()){
                    words.push_back(word);
                    word.clear();
                }
            }else{
                word+=c;
            }
        }
        if(!word.empty()){
            words.push_back(word);
        }
        long long res = 1;
        for(string &w: words){
            unordered_map<char,int> freq;
            for(char c: w){
                freq[c]++;
            }
            long long permutations = fact[w.length()];
            for(auto &[ch,count]: freq){
                permutations = (permutations * invfact[count])%mod;
            }
            res= (res*permutations)%mod;
        }
        return res;
    }
};