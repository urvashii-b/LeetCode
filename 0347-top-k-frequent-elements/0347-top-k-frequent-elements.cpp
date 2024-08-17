class Solution {
public:
    typedef pair<int,int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int &i:nums){
            freq[i]++;
        }
        priority_queue<P,vector<P>,greater<P>> pq;
        for(auto& it: freq){
            int val = it.first;
            int frequency = it.second;
            
            pq.push({frequency,val});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> res;
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            res.push_back(p.second);
        }
        return res;
    }
};