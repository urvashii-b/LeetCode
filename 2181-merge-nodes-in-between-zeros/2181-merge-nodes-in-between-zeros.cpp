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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = head->next;
        ListNode* temp = dummy;
        while(temp!=NULL){
            int sum = 0;
            while(temp->val!=0){
                sum = sum+temp->val;
                temp=temp->next;
            }
            dummy->val = sum;
            temp=temp->next;
            dummy->next = temp;
            dummy=dummy->next;
        }
        return head->next;
    }
};