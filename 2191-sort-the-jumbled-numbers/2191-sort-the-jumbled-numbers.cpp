class Solution {
private:
    static bool compare(const pair<int,int> &a, const pair<int,int> &b){
        return a.second<b.second;
    }
    
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = mapping.size();
        for(int i=0;i<n;i++){
            mpp[i]=mapping[i];
        }
        vector<pair<int,int>> mappedNums;
        for(int num:nums){
            int temp = num, newNum = 0, place = 1;
            if(temp==0){
                newNum = mpp[0];
            }else{
                while(temp){
                    int digit = temp%10;
                    temp/=10;
                    newNum = mpp[digit]*place+newNum;
                    place*=10;
                }
            }
            mappedNums.push_back({num,newNum});
        }
        sort(mappedNums.begin(),mappedNums.end(),compare);
        vector<int> ans;
        for(const auto& pair: mappedNums){
            ans.push_back(pair.first);
        }
        return ans;
    }
};