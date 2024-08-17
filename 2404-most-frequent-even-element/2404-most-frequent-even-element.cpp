class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int &num:nums){
            if(num%2==0){
                freq[num]++;
            }
        }
        int mostFrequent = -1;
        int maxFrequency = 0;
        
        for(auto& [num,frequency]: freq){
            if(frequency>maxFrequency || (frequency==maxFrequency && num<mostFrequent)){
                maxFrequency = frequency;
                mostFrequent = num;
            }
        }
        return mostFrequent;
    }
};