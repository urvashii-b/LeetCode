class Solution {
public:
    int calPoints(vector<string>& operations) {
        int val1, val2, ans = 0;
        stack<int> st;
        for(string i: operations){
            if(i=="C"){
                st.pop();
            }
            else if(i=="D"){
                st.push(st.top()*2);
            }else if(i=="+"){
                val1 = st.top();
                st.pop();
                val2 = st.top();
                st.push(val1);
                st.push(val1+val2);
            }else{
                st.push(stoi(i));
            }
        }
        while(st.size()!=0){
            ans+=st.top();
            st.pop();
        }   
        return ans;
    }
};