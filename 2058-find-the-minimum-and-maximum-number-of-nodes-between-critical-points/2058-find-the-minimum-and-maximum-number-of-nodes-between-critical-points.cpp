/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1,-1};
        if(head->next->next==NULL || head->next==NULL || head==NULL) return ans;
        int minDist = INT_MAX;
        ListNode* prev = head;
        ListNode* cur = head->next;
        int index = 1, prevCindex = 0, firstCindex = 0;
        while(cur->next!=nullptr){
            if ((cur->val < prev->val && cur->val < cur->next->val) ||
                (cur->val > prev->val && cur->val > cur->next->val)) {
                if(prevCindex==0){
                    prevCindex = index;
                    firstCindex = index;
                }else{
                    minDist = min(minDist, index - prevCindex);
                    prevCindex = index;
                }
            }
            index++;
            prev = cur;
            cur=cur->next;
        }
        if(minDist!=INT_MAX){
            int maxDist = prevCindex - firstCindex;
            ans = {minDist, maxDist};
        }
        return ans;
    }
};