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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
        int cnt = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        if(cnt==n){ //delete the head
            ListNode* newhead = head->next;
            delete(head);
            return newhead;
        }
        int ans = cnt-n;
        temp = head;
        while(temp!=NULL){
            ans--;
            if(ans==0){
                break;
            }
            temp=temp->next;
        }
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete(delNode);
        return head;
    }
};