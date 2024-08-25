/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                ListNode* temp = head;
                while(temp!=slow){
                    slow=slow->next;
                    temp=temp->next;
                }
                return temp;
            }
        }
        return NULL;
    }
};