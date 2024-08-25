class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 0, n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int i=0, j=1;
        while(j<n){
            vector<int> current = intervals[i];
            vector<int> next = intervals[j];
            int curStart = current[0];
            int curEnd = current[1];
            int nextStart = next[0];
            int nextEnd = next[1];
            if(curEnd<=nextStart){
                i=j;
                j++;
            }else if(curEnd<=nextEnd){
                j++;
                cnt++;
            }
            else if(curEnd>nextEnd){
                i=j;
                j++;
                cnt++;
            }
        }
        return cnt;
    }
};