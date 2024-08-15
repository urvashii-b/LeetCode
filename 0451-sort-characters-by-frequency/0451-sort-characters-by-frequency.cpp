class Solution {
public:
    typedef pair<char,int> P;
    struct lambda{
        bool operator()(P& p1, P& p2){
            return p1.second<p2.second;
        }
    };
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(char &c:s){
            freq[c]++;
        }
        priority_queue<P,vector<P>,lambda> pq;
        for(auto &it:freq){
            pq.push({it.first,it.second});
        }
        string res="";
        while(!pq.empty()){
            P temp = pq.top();
            pq.pop();
            res+=string(temp.second,temp.first);
        }
        return res;
    }
};