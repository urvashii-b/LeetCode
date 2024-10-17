class Solution {
public:
    int maximumSwap(int num) {
    
        string numS = to_string(num);
        int n = numS.size();
        int maxi = num;
        for(int i=0;i<n;i++){
            for(int j=i+1; j<n; j++){
                swap(numS[i],numS[j]);
                maxi = max(maxi,stoi(numS));
                swap(numS[i],numS[j]);
            }
        }
        return maxi;

    }
};