class Solution {
private:
    bool findSucc(vector<int>& hand, int groupSize, int i, int n){
        int next = hand[i]+1;
        hand[i]=-1;
        int cnt = 1;
        i++;
        while(i<n && cnt<groupSize){
            if(hand[i]==next){
                next = hand[i]+1;
                hand[i]=-1;
                cnt++;
            }
            i++;
        }
        return cnt == groupSize;
    }
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0){
            return false;
        }
        std::sort(hand.begin(),hand.end());
        for(int i=0;i<n;i++){
            if(hand[i]>=0){
                if(!findSucc(hand,groupSize, i, n)){
                    return false;
                }
            }
        }
        return true;
    }
};