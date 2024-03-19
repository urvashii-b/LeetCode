class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        for(auto i:nums){
            int rev=0;
            while(i){
                int rem = i%10;
                rev = rev*10 + rem;
                i/=10;
            }
            s.insert(rev);
        }
        return s.size();
    }
};