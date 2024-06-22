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
    ListNode* middleNode(ListNode* head) {
        /*
        ListNode* temp = head;
        int lengthLL = 0;
        while(temp!=NULL){
            lengthLL++;
            temp=temp->next;
        }
        int mid = lengthLL/2 + 1;
        temp = head;
        while(temp!=NULL){
            mid--;
            if(mid==0){
                break;
            }
            temp=temp->next;
        }
        return temp;
        */
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};