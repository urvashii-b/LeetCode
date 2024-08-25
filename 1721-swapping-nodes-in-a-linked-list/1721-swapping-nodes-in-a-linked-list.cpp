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
private:
    int findLength(ListNode* head){
        int cnt = 0;
        while(head!=NULL){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int lengthh = findLength(head);
        int k1 = k;
        int k2 = lengthh-k+1;
        ListNode* l1 = head;
        ListNode* l2 = head;
        while(k1>1){
            l1=l1->next;
            k1--;
        }
        while(k2>1){
            l2=l2->next;
            k2--;
        }
        swap(l1->val,l2->val);
        return head;
    }
};