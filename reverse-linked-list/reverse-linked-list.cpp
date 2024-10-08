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

/*
        nh    head
               fwd
NULL  <---1      2 ----> 3 ---> 4
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* newHead = NULL;
        while(head!=NULL){
            ListNode* fwd = head->next;
            head->next=newHead;
            newHead = head;
            head = fwd;
        }
        return newHead;
    }
};
