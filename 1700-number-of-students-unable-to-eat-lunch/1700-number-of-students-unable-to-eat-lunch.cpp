class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // SIMULATION
        int n = students.size();
        queue<int> studentQueue;
        stack<int> sandwichStack;
        
        for(int i=0;i<n;i++){
            sandwichStack.push(sandwiches[n-i-1]);
            studentQueue.push(students[i]);
        }
        
        int last = 0;
        while(!studentQueue.empty() && last<studentQueue.size()){
            if(sandwichStack.top() == studentQueue.front()){
                sandwichStack.pop();
                studentQueue.pop();
                last = 0;
            }else{
                studentQueue.push(studentQueue.front());
                studentQueue.pop();
                last++;
            }
        }
        return studentQueue.size();
    }
};